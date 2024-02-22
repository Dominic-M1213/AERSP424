#ifndef PILOT // include guard
#define PILOT

# include <string>
# include "Plane.h"

class Pilot
{
private: 
	std::string name; 
	Plane* myPlane;

public:
	Pilot(const std::string& name);
	~Pilot();

	std::string getName() const;
	void setMyPlane(Plane* plane);
};

#endif