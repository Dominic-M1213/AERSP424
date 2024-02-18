# include <iostream>
# include "Plane.h"

int Plane::get_wing() {
	return this->wing;
}

void Plane::set_wing(int wing) {
	this->wing = wing;
}

Plane::Plane() {
	// Constructur function implementation
	// whenever an object is instantiat from a class
	// the constructor function of the class will be
	// called automatically

	std::cout << "Plane Created" << std::endl;
}

Plane::Plane(int wing) {

	std::cout << "Plane Created with wing" << std::endl;
	this->wing = wing;
}

Plane::~Plane(int wing, double tail) :tail(tail) {

	std::cout << "Plane Created with wing and tail" << std::cout;
	this->wing = wing + 1;
}

Plane::~Plane() {

	// deconstructor function implementation
	std::cout << "Plane Destroyed" << std::endl;
}