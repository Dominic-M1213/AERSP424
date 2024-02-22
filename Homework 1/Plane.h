#ifndef PLANE // include guard
#define PLANE

# include <string>
# include "FlightMap.h"

class Plane
{
private: 
	double pos;
	double vel;
	double distance;
	bool at_SCE;
	std::string origin;
	std::string destination;
	FlightMap flightMap;

public:
	Plane(std::string from, std::string to);
	~Plane();

	// existing methods
	void operate(double dt);
	double getPos();
	std::string getOrigin();
	std::string getDestination();
	bool getAt_SCE();
	double getVel();
	void setVel(double vel);
	

};
#endif