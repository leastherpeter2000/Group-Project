#include <iostream>
#include <string>
#include <sqlite3.h>
#include "lorries.h"

void Lorries::lorryDBStart() {
	sqlite3* db;
	int rc;

	rc = sqlite3_open("lorries.db", &db);
	if (rc != SQLITE_OK) {
		std::cerr << "Error while opening database: " << sqlite3_errmsg(db) << std::endl;
		sqlite3_close(db);
	}

	const char* sql = "CREATE TABLE IF NOT EXISTS Lorries (lorryID INTEGER PRIMARY KEY, description TEXT, identifier TEXT, maxTonnage INTEGER)";
	rc = sqlite3_exec(db, sql, NULL, 0, NULL);
	if (rc != SQLITE_OK) {
		std::cerr << "Error while creating database: " << sqlite3_errmsg(db) << std::endl;
		sqlite3_close(db);
	}

	sql = "INSERT OR IGNORE INTO Lorries (lorryID, description, identifier, maxTonnage) VALUES \
		(1, 'Light Goods Vehicle', '2A', 3.5), \
		(2, 'Heavy Goods Vehicle', '2A Smaller', 7.5), \
		(3, 'Heavy Goods Vehicle', '2A Bigger', 18), \
		(4, 'Heavy Goods Vehicle', '3A', 26), \
		(5, 'Heavy Goods Vehicle', '4A Rigid', 32), \
		(6, 'Heavy Goods Vehicle', '4A Artic.', 38), \
		(7, 'Heavy Goods Vehicle', '5A Artic.', 40), \
		(8, 'Heavy Goods Vehicle', '6A Artic.', 44)";
	rc = sqlite3_exec(db, sql, NULL, 0, NULL);
	if (rc != SQLITE_OK) {
		std::cerr << "Error while inserting data: " << sqlite3_errmsg(db) << std::endl;
		sqlite3_close(db);
	}
}