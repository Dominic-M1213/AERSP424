# include <iostream>
# include <array>
# include <vector>
# include <map>
# include <utility>
# include <iomanip>
# include <sstream>
# include <string>
# include "Plane.h"
# include "Pilot.h"
# include "makePlane.h"
# include "FlightMap.h"

std::string formatTime(double seconds) {
	int days = static_cast<int>(seconds) / (3600 * 24);
	seconds = static_cast<int>(seconds) % (3600 * 24);
	int hours = static_cast<int>(seconds) / 3600;
	seconds = static_cast<int>(seconds) % 3600;
	int minutes = static_cast<int>(seconds) / 60;
	seconds = static_cast<int>(seconds) % 60;

	std::stringstream timeStream;
	timeStream << days << ":"
		<< std::setfill('0') << std::setw(2) << hours << ":"
		<< std::setfill('0') << std::setw(2) << minutes << ":"
		<< std::setfill('0') << std::setw(2) << static_cast<int>(seconds);
	return timeStream.str();
}

int main() {
	std::cout << "AERSP424: Homework 1" << std::endl;
	// Set Use a decimal precision of 0.01 lbs
	std::cout << std::fixed << std::showpoint << std::setprecision(2);
	//makePlane myBuiltPlane;
	Plane myPlane("SCE","PHL");
	myPlane.setVel(400);

	double timestep = 15;
	int max_iter = 95;

	for (int i = 0; i <= max_iter; i++) {
		int time = timestep * i;
		myPlane.operate(timestep);
		std::cout << "Time: " << formatTime(time)
			<< "	Position: " << myPlane.getPos() << std::endl;
	}

	return 0;
}

