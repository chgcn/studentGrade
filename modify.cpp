#include "modify.h"
extern AccountHandle *Account;
extern char* dbc;

static int insertCallback(void * notused, int argc, char **argv, char **azColName) {
	int i;
	for (i = 0; i<argc; i++) {
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}
	printf("\n");
	return 0;
}

static int checkCallback(void * notused, int argc, char **argv, char **azColName) {
	int i;
	if (argc == 0)
	{
		return 1;
	}
	for (i = 0; i<argc; i++) {
		//printf("%s ", argv[i] ? argv[i] : "NULL");
		if (!strcmp("1", argv[i]))
		{
			printf("You are admin, welcome!\n");
			return 0;
		}
		else
		{
			printf("You are not admin, cannot modify records!\n");
			return 1;
		}
	}
	printf("\n");
	return 0;
}

int modify(string sqlstring)
{

	const char * sql = sqlstring.data();

	sqlite3 *db;
	char *zerrmsg = 0;
	int rc;
	rc = sqlite3_open(dbc, &db);
	if (rc) {
		fprintf(stderr, "can't open database: %s\n", sqlite3_errmsg(db));
		sqlite3_close(db);
		return 1;
	}
	
	if (SQLITE_OK != sqlite3_exec(db, sql, insertCallback, 0, &zerrmsg))
		
	{
		fprintf(stderr, "sql error: %s\n", zerrmsg);
		sqlite3_free(zerrmsg);
		return 1;
				
	}
	sqlite3_close(db);
	return 0;
}

int checkUserPrivilege()
{
	string sqlstring = "SELECT UserType FROM SYS_USER WHERE UserName = '" + Account->getUsername() + "'";
	const char * sql = sqlstring.data();
	sqlite3 *db;
	char *zerrmsg = 0;
	int rc;

	rc = sqlite3_open(dbc, &db);
	if (rc) {
		fprintf(stderr, "can't open database: %s\n", sqlite3_errmsg(db));
		sqlite3_close(db);
		return 1;
	}

	rc = sqlite3_exec(db, sql, checkCallback, 0, &zerrmsg);

	if (rc != SQLITE_OK) {
		fprintf(stderr, "sql error: %s\n", zerrmsg);
		sqlite3_free(zerrmsg);
	}

	sqlite3_close(db);
	return rc;
}