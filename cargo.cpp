#include <iostream>
#include "cargo.h"

void Cargo::inputDimensions() {
	int conditionChoice;

	std::cout << "Enter cargo height: " << std::endl;
	std::cin >> cargoHeight;
	std::cout << "Enter cargo width: " << std::endl;
	std::cin >> cargoWidth;
	std::cout << "Enter cargo length: " << std::endl;
	std::cin >> cargoLength;
	bool validWeight = false;
	while (!validWeight) {
		std::cout << "Enter cargo weight: " << std::endl;
		std::cin >> cargoWeight;

		try {
			if (cargoWeight > 44) {
				throw std::out_of_range("Weight exceeds limit of 44");
			}
			validWeight = true;
		}
		catch (const std::out_of_range& e) {
			std::cout << "Invalid weight entered: " << e.what() << std::endl;
		}
	}
	if (cargoWeight <= 3.5) {
		lorryType = 1;
	} 
	else if (cargoWeight > 3.5 && cargoWeight <= 7.5) {
		lorryType = 2;
	} 
	else if (cargoWeight > 7.5 && cargoWeight <= 18) {
		lorryType = 3;
	}
	else if (cargoWeight > 18 && cargoWeight <= 26) {
		lorryType = 4;
	}
	else if (cargoWeight > 26 && cargoWeight <= 32) {
		lorryType = 5;
	}
	else if (cargoWeight > 32 && cargoWeight <= 38) {
		lorryType = 6;
	}
	else if (cargoWeight > 38 && cargoWeight <= 40) {
		lorryType = 7;
	}
	else if (cargoWeight > 40 && cargoWeight <= 44) {
		lorryType = 8;
	}
	std::cout << "\nDoes your cargo have any special handling conditions?" << std::endl << "1. Regular" << std::endl << "2. Fragile" << std::endl << "3. Frozen" << std::endl;
	std::cin >> conditionChoice;
	if (conditionChoice == 1) {
		cargoCondition = "Regular";
	}
	else if (conditionChoice == 2) {
		cargoCondition = "Fragile";
	}
	else if (conditionChoice == 3) {
		cargoCondition = "Frozen";
	}
}