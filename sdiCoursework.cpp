//sdi_coursework.cpp
//SOFT20091 Software Design and Implementation
//Coursework Assessment
//Group A2
//Dustin Sumartlie, Leasther Anak Peter, Rodney Sydney, Weiyi Zhu

#include <iostream>
#include <sqlite3.h>
#include "cargoOwner.h"
#include "transportCompany.h"
#include "Driver.h"
#include "cities.h"
#include "lorries.h"
#include "cargo.h"
#include "order.h"

int main() {
	//declare and intialise variables
	int mainmenuChoice;
	bool inputCheck = false;
	int typeChoice;
	int caOwMenuChoice;
	cargoOwner cargoUser;
	transportComp tcUser;
	Driver driverUser;
	Lorries lorry;
	Order order;

	lorry.lorryDBStart();

	std::cout << "e-Transport Marketplace \n" << endl;

	//loop until valid user input is received
	while (!inputCheck) {
		std::cout << "(1) Register" << endl;
		std::cout << "(2) Login \n" << endl;
		std::cout << "Type your choice here: ";
		cin >> mainmenuChoice; //user input for main menu choice

		//switch statement for main menu choice
		switch (mainmenuChoice) {
		//user selects register
		case 1:
			std::cout << "\nUser Registration" << endl;
			std::cout << "\nSelect your user type: " << endl;
			std::cout << "(1) Cargo Owner" << endl;
			std::cout << "(2) Transportation Company" << endl;
			std::cout << "(3) Driver \n" << endl;
			std::cout << "Type your choice here: ";
			cin >> typeChoice;
			switch (typeChoice) {
			case 1:
				std::cout << "\nUser Registration for Cargo Owner" << endl;
				cargoUser.cargoOwnerDBStart();
				cargoUser.cargoOwnerReg();
				break;
			case 2:
				std::cout << "\nUser Registration for Transportation Company" << endl;
				tcUser.tcDBStart();
				tcUser.tcReg();
				break;
			case 3:
				std::cout << "\nUser Registration for Driver" << endl;
				driverUser.driverDBStart();
				driverUser.driverReg();
				break;
			}
			inputCheck = true;
			break;
		//user selects login, functionality not yet implemented
		case 2:
			std::cout << "\nLogin" << endl;
			std::cout << "\nSelect your user type: " << endl;
			std::cout << "(1) Cargo Owner" << endl;
			std::cout << "(2) Transportation Company" << endl;
			std::cout << "(3) Driver \n" << endl;
			std::cout << "Type your choice here: ";
			cin >> typeChoice;
			switch (typeChoice) {
			case 1:
				std::cout << "\nLogin for Cargo Owner" << endl;
				cargoUser.cargoOwnerLogin();
				std::cout << "\nWelcome, " << cargoUser.getUserID() << endl;
				std::cout << "\n(1) Place Order" << std::endl << "(2) View Orders" << std::endl;
				cin >> caOwMenuChoice;
				switch (caOwMenuChoice) {
				case 1:
					order.placeOrder(cargoUser);
					break;
				case 2:
					order.viewOrder(cargoUser);
					break;
				}
				break;
			case 2:
				std::cout << "\nLogin for Transportation Company" << endl;
				tcUser.tcLogin();
				break;
			case 3:
				std::cout << "\nLogin Registration for Driver" << endl;
				driverUser.driverLogin();
				break;
			}
			inputCheck = true;
			break;
		//error message
		default:
			cerr << "\nPlease input (1) or (2)" << endl;
			break;
		}
	}
}
