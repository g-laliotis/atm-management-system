#include "../include/header.h"

// SQLite database support - optional bonus feature
// Uncomment and link with -lsqlite3 to enable

/*
#include <sqlite3.h>

static sqlite3 *db = NULL;

int initDatabase() {
    int rc = sqlite3_open("./data/atm.db", &db);
    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return 0;
    }
    
    char *errMsg = 0;
    const char *sqlUsers = "CREATE TABLE IF NOT EXISTS users ("
                          "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                          "name TEXT UNIQUE NOT NULL,"
                          "password TEXT NOT NULL);";
    
    const char *sqlRecords = "CREATE TABLE IF NOT EXISTS records ("
                            "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                            "userId INTEGER NOT NULL,"
                            "name TEXT NOT NULL,"
                            "accountNbr INTEGER NOT NULL,"
                            "depositDay INTEGER,"
                            "depositMonth INTEGER,"
                            "depositYear INTEGER,"
                            "country TEXT,"
                            "phone INTEGER,"
                            "amount REAL,"
                            "accountType TEXT,"
                            "FOREIGN KEY(userId) REFERENCES users(id));";
    
    rc = sqlite3_exec(db, sqlUsers, 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
        return 0;
    }
    
    rc = sqlite3_exec(db, sqlRecords, 0, 0, &errMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
        return 0;
    }
    
    return 1;
}

void closeDatabase() {
    if (db) {
        sqlite3_close(db);
    }
}
*/

// Placeholder for text file mode
void initDatabase() {}
void closeDatabase() {}
