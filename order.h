#include "cargo.h"
#include "cities.h"
#include "cargoOwner.h"
#pragma once

class Order : protected Cargo, Cities {
protected:
	double deliveryFee;
	Cities cities;
	Cargo cargo;
	cargoOwner caOw;
public:
	void orderDBStart();
	void orderDBInsert(cargoOwner caOw);
	void placeOrder(cargoOwner caOw);
	void viewOrder(cargoOwner caOw);
	void feeCalc();
};