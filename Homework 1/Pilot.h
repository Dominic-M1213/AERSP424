#ifndef PILOT // include guard
#define PILOT

# include <string>
class Plane;

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
	Plane *Pilot::getMyPlane() const;
};

#endif