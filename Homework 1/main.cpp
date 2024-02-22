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
    makePlane myBuiltPlane;
    // Create plane and pilots
    Plane myPlane("SCE", "PHL");
    myPlane.setVel(400); // Assuming velocity is in miles per hour

    Pilot pilotAlpha("Alpha");
    Pilot pilotBravo("Bravo");

    // Assign the plane to the pilots
    pilotAlpha.setMyPlane(&myPlane);
    pilotBravo.setMyPlane(&myPlane);

    // Simulation parameters
    int timestep = 9;
    int max_iter = 2000;
    bool isAlphaPilot = true;

    // Start the simulation
    for (int i = 0; i <= max_iter; i++) {
        int time = timestep * i;

        if (myPlane.getAt_SCE()) {
            std::cout << "\nThe plane " << &myPlane << " is at SCE." << std::endl;
            // Switch pilot
            if (isAlphaPilot) {
                std::cout << "Pilot " << pilotAlpha.getName() << " with certificate number " << &pilotAlpha
                    << " is in control of a plane: " << &myPlane << std::endl;
                //pilotAlpha.takeControl();
            }
            else {
                std::cout << "Pilot " << pilotBravo.getName() << " with certificate number " << &pilotAlpha
                    << " is in control of a plane: " << &myPlane << std::endl;
                //pilotBravo.takeControl();
            }
            isAlphaPilot = !isAlphaPilot; // Toggle the pilot control
            myPlane.resetForNextLeg(); // Reset plane's position for the next leg
        }

        // Operate the plane
        myPlane.operate(timestep);
        //std::cout << "Time: " << formatTime(time) << " seconds. "
            //<< "Position: " << myPlane.getPos() << " miles." << std::endl;
    }

	return 0;
}

