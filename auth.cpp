#include "auth.h"
char * passwordc;
AccountHandle *WrongPasswordIns = new WrongPassword();
AccountHandle *Account = new CheckPassword(WrongPasswordIns);

static int AuthCallback(void * notused, int argc, char **argv, char **azColName) {
	int i;
	if (argc == 0)
	{
		return 1;
	}
	for (i = 0; i<argc; i++) {
		//printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
		if (!strcmp(passwordc, argv[i]))
		{
			printf("Authentication Succeed!\n");
			return 0;
		}
		else
		{
			printf("Authentication Failed!\n");
			return 1;
		}
	}
	printf("\n");
	return 0;
}

int Auth()
{

	while(WrongPasswordIns->getCount() < 3)
	{
		Account->HandleRequest();
		if (Account->getState())
		{
			return 0;
		}
	}
	return 1;
	
}

int EnteringAndFetching()
{
	
	string s;
	cout << "Enter Username: ";
	cin >> s;
	Account->setUsername(s);
	cout << "Enter Password: ";
	cin >> s;
	Account->setPassword(s);
	passwordc = (char*)s.data();
	string sqlstring = "SELECT UserPwd FROM SYS_USER WHERE UserName = '" + Account->getUsername() + "'";
	const char * sql = sqlstring.data();

	sqlite3 *db;
	char *zerrmsg = 0;
	int rc;

	/*if (argc != 2) {
	fprintf(stderr, "usage: %s database", argv[0]);
	return(1);
	}*/
	
	rc = sqlite3_open(dbc, &db);
	if (rc) {
		fprintf(stderr, "can't open database: %s\n", sqlite3_errmsg(db));
		sqlite3_close(db);
		return 1;
	}

	
	rc = sqlite3_exec(db, sql, AuthCallback, 0, &zerrmsg);
	
	struct sqlite3_stmt *selectstmt;
	int result = sqlite3_prepare_v2(db, sql, -1, &selectstmt, NULL);
	if (result == SQLITE_OK)
	{
		if (sqlite3_step(selectstmt) == SQLITE_ROW)
		{
			// record found
		}
		else
		{
			printf("record not found\n");
			sqlite3_close(db);
			return 1;
		}
	}
	sqlite3_finalize(selectstmt);
	if (rc != SQLITE_OK ) {
		fprintf(stderr, "sql error: %s\n", zerrmsg);
		sqlite3_free(zerrmsg);
	}
	
	sqlite3_close(db);
	return 0;
}
