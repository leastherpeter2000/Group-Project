#pragma once
#include <string>
#include "user.h"

class Cargo{
protected:
	int cargoHeight;
	int cargoWidth;
	int cargoLength;
	int cargoWeight;
	int lorryType;
	std::string cargoCondition;
public:
	void inputDimensions();
	int getHeight() const { return cargoHeight; }
	int getWidth() const { return cargoWidth; }
	int getLength() const { return cargoLength; }
	int getWeight() const { return cargoWeight; }
	int getLorryType() const { return lorryType; }
	std::string getCondition() const { return cargoCondition; }
};