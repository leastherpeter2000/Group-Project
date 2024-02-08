#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
#include "cities.h"

int Cities::citiesCalc() {
    //map city ID to location
    std::unordered_map<int, int> cityLoc{
        {1, 1},
        {2, 10},
        {3, 34},
        {4, 50},
        {5, 57},
        {6, 69},
        {7, 79},
        {8, 86},
        {9, 92},
        {10, 99},
        {11, 115},
        {12, 135}
    };

    //map city ID to city name
    std::unordered_map<int, std::string> cityNames{
        {1, "Bournemouth"},
        {2, "Southampton"},
        {3, "Dover"},
        {4, "London"},
        {5, "Milton Keynes"},
        {6, "Birmingham"},
        {7, "Nottingham"},
        {8, "Sheffield"},
        {9, "Manchester"},
        {10, "Leeds"},
        {11, "Newcastle upon Tyne"},
        {12, "Edinburgh"}
    };

    //sort map by ID
    std::vector<std::pair<int, int>> sortedCityLoc(cityLoc.begin(), cityLoc.end());
    std::sort(sortedCityLoc.begin(), sortedCityLoc.end(),
        [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
            return a.first < b.first;
        });

    int originCityId, destCityId;
    std::cout << "\nList of Available Cities" << std::endl <<
        "1. Bournemouth" << std::endl <<
        "2. Southampton" << std::endl <<
        "3. Dover" << std::endl <<
        "4. London" << std::endl <<
        "5. Milton Keynes" << std::endl <<
        "6. Birmingham" << std::endl <<
        "7. Nottingham" << std::endl <<
        "8. Sheffield" << std::endl <<
        "9. Manchester" << std::endl <<
        "10. Leeds" << std::endl <<
        "11. Newcastle upon Tyne" << std::endl <<
        "12. Edinburgh" << std::endl;
    std::cout << "\nEnter the ID of the origin city: ";
    std::cin >> originCityId;
    std::cout << "Enter the ID of the destination city: ";
    std::cin >> destCityId;

    //find origin city location
    auto originCity = std::lower_bound(sortedCityLoc.begin(), sortedCityLoc.end(),
        std::make_pair(originCityId, 0),
        [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
            return a.first < b.first;
        });

    if (originCity == sortedCityLoc.end() || originCity->first != originCityId) {
        std::cout << "Origin city not found" << std::endl;
        return 0;
    }

    //find destination city location
    auto destCity = std::lower_bound(sortedCityLoc.begin(), sortedCityLoc.end(),
        std::make_pair(destCityId, 0),
        [](const std::pair<int, int>& a, const std::pair<int, int>& b) {
            return a.first < b.first;
        });

    if (destCity == sortedCityLoc.end() || destCity->first != destCityId) {
        std::cout << "Destination city not found" << std::endl;
        return 0;
    }

    //print name and locations
    std::cout << "The location of the origin city (" << cityNames[originCityId] << ") is: " << originCity->second << std::endl;
    std::cout << "The location of the destination city (" << cityNames[destCityId] << ") is: " << destCity->second << std::endl;

    int distance = std::abs(cityLoc[destCityId] - cityLoc[originCityId]);
    std::cout << "The distance between the two cities is: " << distance << std::endl;

    originCityName = cityNames[originCityId];
    destCityName = cityNames[destCityId];
    dist = distance;

    return 0;
}