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

	Plane();

	Plane(int wing);
	Plane(int wing, double tail);

	~Plane();
};

static void print_something();
void another_print();
#endif