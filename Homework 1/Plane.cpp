# include <iostream>
# include <numeric>
# include <vector>
# include <string>
# include <algorithm>
# include "Plane.h"
# include "Pilot.h"

// Plane Methods
double Plane::getPos() {
    return this->pos;
}

double Plane::getVel() {
    return this->vel;
}

void Plane::setVel(double vel) {
    this->vel = vel;
}

bool Plane::getAt_SCE() {
    return this->at_SCE;
}

std::string Plane::getOrigin() {
    return this->origin;
}

std::string Plane::getDestination() {
    return this->destination;
}

Plane::Plane(std::string from, std::string to) 
    : pos(0), vel(0), distance(0), at_SCE(false), origin(from), destination(to) {
    
    flightMap.addFlight("SCE", "PHL", 160);
    flightMap.addFlight("SCE", "ORD", 640);
    flightMap.addFlight("SCE", "EWR", 220);

    this->origin = from;
    this->destination = to;
    getPos();
    getOrigin();
    getDestination();
    getAt_SCE();
    getVel();

    // Set the distance based on the origin and destination
    distance = flightMap.getDistance(from, to);

    std::cout << "\nPlane Created with address " << this << std::endl;
    flightMap.displayFlights(from, to, distance);
}


Plane::~Plane() {

    // deconstructor function implementation
    std::cout << "\nPlane Destroyed" << std::endl;
}

void Plane::operate(double dt) {
    double vel_mps = vel / 3600.0;
    
    if (dt < 0) {
        dt = 0.0;
    }

    if (vel_mps < 0) {
        vel_mps = 0.0;
    }

    if (pos < distance) {
        pos += vel_mps * dt; 
        
        if (pos < 0) {
            pos = 0.0;
        }
        else if (pos > distance) {
            pos = distance;
        }

        at_SCE = false; // Plane is not at SCE if it's still in transit
    }
    else {
        if (destination == "SCE") {
            at_SCE = true;
        }
        else {
            at_SCE = false;
        }
        std::swap(origin, destination);
        pos = 0.0;
    }
}


void Plane::resetForNextLeg() {
    this->pos = 0;
}
