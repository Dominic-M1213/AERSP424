# include <iostream>
# include <memory>
# include "Pilot_ModCPP.h"
# include "Plane_ModCPP.h"

// Constructor
Pilot_ModCPP::Pilot_ModCPP(const std::string& name) : name(name), myPlane(nullptr) {
    std::cout << "\nPilot " << this->name << ", memory address: " << this
        << ", is at the gate, ready to board the plane" << std::endl;
}

// Destructor
Pilot_ModCPP::~Pilot_ModCPP() {
    std::cout << "\nPilot " << this->name << " is out of the plane" << std::endl;
}

// getName function
std::string Pilot_ModCPP::getName() const {
    return this->name;
}

// setMyPlane function
void Pilot_ModCPP::setMyModernPlane(std::shared_ptr < Plane_ModCPP> plane) {
    this->myPlane = std::move(plane);
}

std::shared_ptr <Plane_ModCPP> Pilot_ModCPP::getMyModernPlane() const {
    return myPlane;
}
