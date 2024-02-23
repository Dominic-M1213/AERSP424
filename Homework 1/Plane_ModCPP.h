#ifndef PLANE_MODCPP // include guard
#define PLANE_MODCPP

# include <string>
# include <memory>
# include "FlightMap.h"
# include "Pilot_ModCPP.h"

class Plane_ModCPP
{
private:
	double pos;
	double vel;
	double distance;
	bool at_SCE;
	std::string origin;
	std::string destination;
	FlightMap flightMap;
	std::unique_ptr<Pilot_ModCPP> pilotInControl;

public:
	Plane_ModCPP(std::string from, std::string to);
	~Plane_ModCPP();

	// existing methods
	void operate(double dt);
	double getPos();
	std::string getOrigin();
	std::string getDestination();
	bool getAt_SCE();
	double getVel();
	void setVel(double vel);
	void resetForNextLeg();
};
#endif