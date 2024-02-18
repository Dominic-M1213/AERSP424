#ifndef PLANE // include guard
#define PLANE
class Plane
{
private: // not necessary, private is default setting of a class
	int wing; // variable member
	double tail;

public:
	// function members
	int get_wing();
	void set_wing(int wing);

	Plane(int wing);
	Plane(int wing, double tail);

};
#endif