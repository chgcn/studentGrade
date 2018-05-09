#include "Auth.h"
char * passwordc;

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

	PasswordHandle *WrongPasswordIns = new WrongPassword();
	PasswordHandle *Password = new CheckPassword(WrongPasswordIns);
	while(WrongPasswordIns->getCount() < 3)
	{
		Password->HandleRequest();
		if (Password->getState())
		{
			return 0;
		}
	}
	return 1;
	
}

int EnteringAndFetching()
{
	
	string username, password;
	cout << "Enter Username: ";
	cin >> username;
	cout << "Enter Password: ";
	cin >> password;
	passwordc = (char*)password.data();
	string sqlstring = "SELECT Password FROM Auth WHERE Username = '" + username + "'";

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
		return(1);
	}

	const char * sql = sqlstring.data();
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
			return 1;
		}
	}
	if (rc != SQLITE_OK ) {
		fprintf(stderr, "sql error: %s\n", zerrmsg);
		sqlite3_free(zerrmsg);
		return 1;
	}
	
	sqlite3_close(db);
	return 0;
}