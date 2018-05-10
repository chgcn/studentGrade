#include "Display.h"

static int callback(void * notused, int argc, char **argv, char **azColName) {
	int i;
	if (argc == 0)
	{
		return 1;
	}
	for (i = 0; i< argc; i++) {
		printf("%s ", argv[i] ? argv[i] : "NULL");
	}
	printf("\n");
	return 0;
}

void display(string sqlstring)
{
	
	const char * sql = sqlstring.data();

	sqlite3 *db;
	char *zerrmsg = 0;
	int rc;

	rc = sqlite3_open(dbc, &db);
	if (rc) {
		fprintf(stderr, "can't open database: %s\n", sqlite3_errmsg(db));
		sqlite3_close(db);
		return;
	}

	rc = sqlite3_exec(db, sql, callback, 0, &zerrmsg);

	if (rc != SQLITE_OK) {
		fprintf(stderr, "sql error: %s\n", zerrmsg);
		sqlite3_free(zerrmsg);
	}

	sqlite3_close(db);
}