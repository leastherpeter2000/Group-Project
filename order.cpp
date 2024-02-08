#include <iostream>
#include <sqlite3.h>
#include "order.h"
#include "cities.h"
#include "cargoOwner.h"

void Order::orderDBStart() {
	sqlite3* db;
	int rc;

	rc = sqlite3_open("orders.db", &db);
	if (rc != SQLITE_OK) {
		cerr << "Error while opening database: " << sqlite3_errmsg(db) << endl;
		sqlite3_close(db);
	}

	const char* sql = "CREATE TABLE IF NOT EXISTS orders \
		(orderID INTEGER PRIMARY KEY, \
		originCity TEXT, \
		destCity TEXT, \
		distance INTEGER, \
		height INTEGER, \
		length INTEGER, \
		width INTEGER, \
		weight INTEGER, \
		cargoCondition TEXT, \
		deliveryFee TEXT, \
		caOwID INTEGER, \
		driverID INTEGER)";
	rc = sqlite3_exec(db, sql, NULL, 0, NULL);
	if (rc != SQLITE_OK) {
		cerr << "Error while creating database: " << sqlite3_errmsg(db) << endl;
		sqlite3_close(db);
	}
}

void Order::orderDBInsert(cargoOwner caOw) {
	sqlite3* db;
	int rc;

	rc = sqlite3_open("orders.db", &db);
	if (rc != SQLITE_OK) {
		cerr << "Error while opening database: " << sqlite3_errmsg(db) << endl;
		sqlite3_close(db);
	}

	string tableName = "orders";

	string sql = "INSERT INTO " + tableName + 
		"(originCity, destCity, distance, height, length, width, weight, cargoCondition, deliveryFee, caOwID) \
		VALUES (" + "'" + cities.getOriginCityName() + "', '" + cities.getDestCityName() + "', '" + std::to_string(cities.getDist()) + "', '" + std::to_string(cargo.getHeight()) + "', '" + std::to_string(cargo.getLength()) + "', '" + std::to_string(cargo.getWidth()) + "', '" + std::to_string(cargo.getWeight()) + "', '" + cargo.getCondition() + "', '" + std::to_string(deliveryFee) + "', '" + std::to_string(caOw.getUserID()) + "');";
	rc = sqlite3_exec(db, sql.c_str(), NULL, 0, NULL);
	if (rc != SQLITE_OK) {
		cerr << "Error while inserting into database: " << sqlite3_errmsg(db) << endl;
		sqlite3_close(db);
	}
}

void Order::viewOrder(cargoOwner caOw) {
	sqlite3* db;
	int rc;

	rc = sqlite3_open("orders.db", &db);
	if (rc != SQLITE_OK) {
		cerr << "Error while opening database: " << sqlite3_errmsg(db) << endl;
		sqlite3_close(db);
	}

	string tableName = "orders";
	string sql = "SELECT * FROM " + tableName + " WHERE caOwID='" + std::to_string(caOw.getUserID()) + "';";
	sqlite3_stmt* stmt;
	rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, NULL);
	if (rc != SQLITE_OK) {
		cerr << "Error while selecting from database: " << sqlite3_errmsg(db) << endl;
		sqlite3_close(db);
	}

	while (sqlite3_step(stmt) == SQLITE_ROW) {
		int orderID = sqlite3_column_int(stmt, 0);
		string originCity = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
		string destCity = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)));
		int distance = sqlite3_column_int(stmt, 3);
		int height = sqlite3_column_int(stmt, 4);
		int length = sqlite3_column_int(stmt, 5);
		int width = sqlite3_column_int(stmt, 6);
		int weight = sqlite3_column_int(stmt, 7);
		string cargoCondition = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 8)));
		string deliveryFee = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 9)));

		cout << "Order ID: " << orderID << endl;
		cout << "Cargo Order from " << originCity << " to " << destCity << endl;
		cout << "Distance: " << distance << endl;
		cout << "Dimensions: " << height << "x" << width << "x" << length << endl;
		cout << "Weight: " << weight << endl;
		cout << "Condition: " << cargoCondition << endl;
		cout << "Delivery Fee: " << deliveryFee << endl;
		cout << endl;
	}

	sqlite3_finalize(stmt);
	sqlite3_close(db);
}

void Order::feeCalc() {
	deliveryFee = 0.85 * cities.getDist() * cargo.getLorryType();
}

void Order::placeOrder(cargoOwner caOw) {
	cities.citiesCalc();
	cargo.inputDimensions();
	feeCalc();

	std::cout << "\nCargo Order from " << cities.getOriginCityName() << " to " << cities.getDestCityName() << std::endl <<
		"Distance: " << cities.getDist() << std::endl <<
		"Lorry Band: " << cargo.getLorryType() << std::endl <<
		"Cargo Condition: " << cargo.getCondition() << std::endl <<
		"Delivery Fee: GBP" << deliveryFee;

	std::cout << "\nPlease confirm that the above detail is correct." << std::endl <<
		"Type (Y) to confirm: ";

	char confirm;
	std::cin >> confirm;
	if (toupper(confirm) == 'Y') {
		orderDBStart();
		orderDBInsert(caOw);
	}
}