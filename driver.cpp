#include <string>
#include <iostream>
#include "driver.h"
#include <sqlite3.h>
#include "hashPassword.h"


using namespace std;

void Driver::driverDBStart() {
	sqlite3* db;
	int rc;

	rc = sqlite3_open("driver.db", &db);
	if (rc != SQLITE_OK) {
		cerr << "Error while opening database: " << sqlite3_errmsg(db) << endl;
		sqlite3_close(db);
	}

	const char* sql = "CREATE TABLE IF NOT EXISTS Driver (userID INTEGER PRIMARY KEY, firstName TEXT, surname TEXT, NInumber TEXT, licenceNumber TEXT, username TEXT, email TEXT, password TEXT, address TEXT, businessAdd TEXT, mobileNo INTEGER, businessNo INTEGER)";
	rc = sqlite3_exec(db, sql, NULL, 0, NULL);
	if (rc != SQLITE_OK) {
		cerr << "Error while creating database: " << sqlite3_errmsg(db) << endl;
		sqlite3_close(db);
	}
}

void Driver::driverReg() {
	sqlite3* db;
	int rc;

	rc = sqlite3_open("driver.db", &db);
	if (rc != SQLITE_OK) {
		cerr << "Error while opening database: " << sqlite3_errmsg(db) << endl;
		sqlite3_close(db);
	}

	cin.ignore();

	cout << "Please enter the requested details below." << endl;
	cout << "\nFirst name: ";
	getline(cin, fname);
	cout << "Surname: ";
	getline(cin, sname);
	cout << "National Insurance Number: ";
	getline(cin, NIno);
	cout << "Driving Licence ID: ";
	getline(cin, licenceNo);
	cout << "Address: ";
	getline(cin, address);
	cout << "Business Address: ";
	getline(cin, businessAdd);
	cout << "Email: ";
	getline(cin, email);
	cout << "Mobile Number: ";
	getline(cin, mobileNo);
	cout << "Business Number: ";
	getline(cin, businessNo);
	cout << "Username: ";
	getline(cin, username);
	cout << "Password: ";
	getline(cin, password);
	password = hashPassword(password);

	string tableName = "Driver";

	string sql = "INSERT INTO " + tableName + "(firstName, surname, NInumber, licenceNumber, email, username, password, address, businessAdd, mobileNo, businessNo) VALUES (" + "'" + fname + "', '" + sname + "', '" + NIno + "', '" + licenceNo + "', '" + email + "', '" + username + "', '" + password + "', '" + businessAdd + "', '" + businessNo + "');";
	rc = sqlite3_exec(db, sql.c_str(), NULL, 0, NULL);
	if (rc != SQLITE_OK) {
		cerr << "Error while inserting into database: " << sqlite3_errmsg(db) << endl;
		sqlite3_close(db);
	}
}

void Driver::driverLogin() {
	sqlite3* db;
	int rc;

	rc = sqlite3_open("Driver.db", &db);
	if (rc != SQLITE_OK) {
		cerr << "Error while opening database: " << sqlite3_errmsg(db) << endl;
		sqlite3_close(db);
		return;
	}

	cin.ignore();

	string username, password;
	cout << "Please enter your login details." << endl;
	cout << "Username: ";
	getline(cin, username);
	cout << "Password: ";
	getline(cin, password);
	password = hashPassword(password);

	string tableName = "Driver";
	string sql = "SELECT * FROM " + tableName + " WHERE username = '" + username + "' AND password = '" + password + "';";
	sqlite3_stmt* stmt;
	rc = sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, NULL);
	if (rc != SQLITE_OK) {
		cerr << "Error while preparing statement: " << sqlite3_errmsg(db) << endl;
		sqlite3_close(db);
		return;
	}

	rc = sqlite3_step(stmt);
	if (rc == SQLITE_ROW) {
		cout << "Login successful" << endl;
	}
	else {
		cerr << "Invalid username or password." << endl;
		cout << "Type (1) to register. Press any other key to exit." << endl;
		int option;
		cin >> option;
		if (option == 1) {
			driverReg();
		}
	}

	sqlite3_finalize(stmt);
	sqlite3_close(db);
}