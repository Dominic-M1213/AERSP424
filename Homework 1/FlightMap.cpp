#include "FlightMap.h"
#include <iostream>

FlightMap::FlightMap() {
    std::cout << "\nFlight Map Created" << std::endl;
}
FlightMap::~FlightMap() {
    std::cout << "\nFlight Map Destoryed" << std::endl;
}

void FlightMap::addFlight(const std::string& source, const std::string& destination, int distance) {
    flightMap[source].push_back(FlightInfo(destination, distance));
}

void FlightMap::displayFlights() const {
    for (const auto& source : flightMap) {
        for (const auto& flight : source.second) {
            std::cout << "There are " << flight.second << "-mile flights between \""
                << source.first << "\" and \"" << flight.first << "\"." << std::endl;
        }
    }
}

void FlightMap::displayFlights(const std::string& source, const std::string& destination, int distance) const {
    std::cout << "There are " << distance << "-mile flights between \""
        << source << "\" and \"" << destination << "\"." << std::endl;
}

double FlightMap::getDistance(const std::string& source, const std::string& destination) const {
    // Search for the flight and return the distance
    for (const auto& flight : flightMap.at(source)) {
        if (flight.first == destination) {
            return flight.second; // Return the distance
        }
    }
    return -1; // Return -1 or throw an exception if the flight is not found
}
