#include "header.h"

// SQLite database support - bonus feature enabled
#ifdef USE_SQLITE
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
    
    printf("\n%s✓ SQLite database initialized successfully!%s\n", COLOR_GREEN, COLOR_RESET);
    return 1;
}

void closeDatabase() {
    if (db) {
        sqlite3_close(db);
    }
}
#else
// Text file mode (default)
int initDatabase() {
    printf("\n%s✓ Using text file storage mode%s\n", COLOR_YELLOW, COLOR_RESET);
    return 1;
}
void closeDatabase() {}
#endif
