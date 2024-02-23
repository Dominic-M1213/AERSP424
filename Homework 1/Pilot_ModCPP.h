#ifndef PILOT_MODCPP // include guard
#define PILOT_MODCPP

# include <string>
# include <memory>

class Plane_ModCPP;

class Pilot_ModCPP
{
private:
	std::string name;
	std::shared_ptr <Plane_ModCPP> myPlane;

public:
	Pilot_ModCPP(const std::string& name);
	~Pilot_ModCPP();

	std::string getName() const;
	void setMyModernPlane(std::shared_ptr <Plane_ModCPP> plane);
	std::shared_ptr <Plane_ModCPP> Pilot_ModCPP::getMyModernPlane() const;

};

#endif