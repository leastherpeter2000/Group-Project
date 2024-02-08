#include <iostream>
#include "transportCompany.h"
#include <sqlite3.h>
#include "hashPassword.h"


using namespace std;

//function to start and create database
void transportComp::tcDBStart() {
	sqlite3* db;
	int rc;

	rc = sqlite3_open("transportCompany.db", &db); 
	if (rc != SQLITE_OK) {
		cerr << "Error while opening database: " << sqlite3_errmsg(db) << endl;
		sqlite3_close(db);
	}

	const char* sql = "CREATE TABLE IF NOT EXISTS transportCompany (userID INTEGER PRIMARY KEY, companyName TEXT, firstName TEXT, surname TEXT, username TEXT, email TEXT, password TEXT, businessAdd TEXT, businessNo INTEGER)";
	rc = sqlite3_exec(db, sql, NULL, 0, NULL);
	if (rc != SQLITE_OK) {
		cerr << "Error while creating database: " << sqlite3_errmsg(db) << endl;
		sqlite3_close(db);
	}
}

//function for registration form and db insert
void transportComp::tcReg() {
	sqlite3* db;
	int rc;

	rc = sqlite3_open("transportCompany.db", &db);
	if (rc != SQLITE_OK) {
		cerr << "Error while opening database: " << sqlite3_errmsg(db) << endl;
		sqlite3_close(db);
	}

	cin.ignore();

	cout << "Please enter the requested details below." << endl;
	cout << "\nCompany name: ";
	getline(cin, companyName);
	cout << "First name: ";
	getline(cin, fname);
	cout << "Surname: ";
	getline(cin, sname);
	cout << "Business Address: ";
	getline(cin, businessAdd);
	cout << "Email: ";
	getline(cin, email);
	cout << "Business Number: ";
	getline(cin, businessNo);
	cout << "Username: ";
	getline(cin, username);
	cout << "Password: ";
	getline(cin, password);
	password = hashPassword(password);

	string tableName = "transportCompany";

	string sql = "INSERT INTO " + tableName + "(companyName, firstName, surname, email, username, password, businessAdd, businessNo) VALUES (" + "'" + companyName + "', '" + fname + "', '" + sname + "', '" + email + "', '" + username + "', '" + password + "', '" + businessAdd + "', '" + businessNo + "');";
	rc = sqlite3_exec(db, sql.c_str(), NULL, 0, NULL);
	if (rc != SQLITE_OK) {
		cerr << "Error while inserting into database: " << sqlite3_errmsg(db) << endl;
		sqlite3_close(db);
	}
}

void transportComp::tcLogin() {
	sqlite3* db;
	int rc;

	rc = sqlite3_open("transportCompany.db", &db);
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

	string tableName = "transportCompany";
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
			tcReg();
		}
	}

	sqlite3_finalize(stmt);
	sqlite3_close(db);
}