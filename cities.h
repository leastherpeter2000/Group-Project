#pragma once

#include <string>

class Cities {
protected:
	std::string originCityName;
	std::string destCityName;
	int dist;
public:
	int citiesCalc();
	std::string getOriginCityName() const { return originCityName; }
	std::string getDestCityName() const { return destCityName; }
	int getDist() const { return dist; }
};