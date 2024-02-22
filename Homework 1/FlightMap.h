#ifndef FLIGHT_MAP_H
#define FLIGHT_MAP_H

#include <map>
#include <vector>
#include <string>

// Define the FlightInfo as a pair of destination and distance
using FlightInfo = std::pair<std::string, int>;

// Define the AdjacencyList as a map from an airport code to a vector of FlightInfo
using AdjacencyList = std::map<std::string, std::vector<FlightInfo>>;

class FlightMap {
private:
    AdjacencyList flightMap;

public:
    FlightMap();
    ~FlightMap();
    void addFlight(const std::string& source, const std::string& destination, int distance);
    void displayFlights() const;
    void displayFlights(const std::string& source, const std::string& destination, int distance) const;
    double getDistance(const std::string& source, const std::string& destination) const;
};

#endif // FLIGHT_MAP_H
