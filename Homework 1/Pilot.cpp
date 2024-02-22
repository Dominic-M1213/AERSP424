# include <iostream>
# include "Pilot.h"
# include "Plane.h"

// Constructor
Pilot::Pilot(const std::string& name) : name(name), myPlane(nullptr) {
    std::cout << "\nPilot " << this->name << ", memory address: " << this
              << ", is at the gate, ready to board the plane." << std::endl;
}

// Destructor
Pilot::~Pilot() {
    std::cout << "\nPilot " << this->name << " is out of the plane." << std::endl;
}

// getName function
std::string Pilot::getName() const {
    return this->name;
}

// setMyPlane function
void Pilot::setMyPlane(Plane* plane) {
    this->myPlane = plane;
}

void Pilot::takeControl() {
    if (myPlane) {
        myPlane->setPilotInControl(this); // Assume this method is implemented in Plane
    }
}
