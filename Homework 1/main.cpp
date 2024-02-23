# include <iostream>
# include <array>
# include <vector>
# include <map>
# include <utility>
# include <iomanip>
# include <sstream>
# include <string>
# include <algorithm>
# include "Plane.h"
# include "Pilot.h"
# include "Plane_ModCPP.h"
# include "Pilot_ModCPP.h"
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

    // --------- 1 ---------
    std::cout << "\n\n# BEGIN ================ Q1 ================ BEGIN #" << std::endl;
    makePlane myBuiltPlane;
    myBuiltPlane.~makePlane();
    std::cout << "# END ================ Q1 ================ END #\n\n" << std::endl;
    
    
    // --------- 2,3,4,5 ---------
    std::cout << "\n\n# BEGIN ================ Q2,3,4,5 ================ BEGIN #" << std::endl;

    std::string from_7 = "SCE"; std::cout << "From 'SCE' -> " << std::endl;
    std::string to_7; std::cout << "To where (Input 'PHL' 'ORD' 'EWR': "; std::cin >> to_7;
    
    std::transform(to_7.begin(), to_7.end(), to_7.begin(), ::toupper); // makes input case insensitive

    // Create plane and pilots
    Plane myPlane(from_7, to_7);
    myPlane.setVel(400); // Assuming velocity is in miles per hour
    // Simulation parameters0000000000000000000
    int timestep = 14;
    int max_iter = 1000;

    // Start the simulation
    for (int i = 0; i <= max_iter; i++) {
        int time = timestep * i;

        // Operate the plane
        myPlane.operate(timestep);
        std::cout << "Time: " << formatTime(time) << " seconds. "
            << "Position: " << myPlane.getPos() << " miles." << std::endl;
    }
    std::cout << "# END ================ Q2,3,4,5 ================ END #\n\n" << std::endl;

    // --------- 6 ---------
    std::cout << "\n\n# BEGIN ================ Q6 ================ BEGIN #" << std::endl;
    Pilot pilotAlpha("Alpha");
    Pilot pilotBravo("Bravo");

    // Assign the plane to the pilots
    pilotAlpha.setMyPlane(&myPlane);
    pilotBravo.setMyPlane(nullptr);

    std::cout << "\n\n# END ================ Q6 ================ END #" << std::endl;
    
    
    // --------- 7 --------
    std::cout << "\n\n# BEGIN ================ Q7 ================ BEGIN #" << std::endl;
    // Simulation parameters
    timestep = 9;
    max_iter = 2000;
    bool isAlphaPilot = true;
    // Start the simulation
    for (int  i = 0; i <= max_iter; i++) {
        int time = timestep * i;

        if (myPlane.getAt_SCE()) {
            std::cout << "\nThe plane " << &myPlane << " is at SCE." << std::endl;
            // Switch pilot
            if (isAlphaPilot) {
                pilotAlpha.setMyPlane(&myPlane);
                pilotBravo.setMyPlane(nullptr);
                std::cout << "Pilot " << pilotAlpha.getName() << " with certificate number " << &pilotAlpha
                    << " is in control of a plane: " << pilotAlpha.getMyPlane() << std::endl;
                std::cout << "Pilot " << pilotBravo.getName() << " with certificate number " << &pilotBravo
                    << " is in control of a plane: " << pilotBravo.getMyPlane() << std::endl;
    
            }
            else {
                pilotAlpha.setMyPlane(nullptr);
                pilotBravo.setMyPlane(&myPlane);
                std::cout << "Pilot " << pilotAlpha.getName() << " with certificate number " << &pilotAlpha
                    << " is in control of a plane: " << pilotAlpha.getMyPlane() << std::endl;
                std::cout << "Pilot " << pilotBravo.getName() << " with certificate number " << &pilotBravo
                    << " is in control of a plane: " << pilotBravo.getMyPlane() << std::endl;
            }
            isAlphaPilot = !isAlphaPilot; // Toggle the pilot control
            myPlane.resetForNextLeg(); // Reset plane's position for the next leg
        }

        // Operate the plane
        myPlane.operate(timestep);
    }

    std::cout << "\n\n# END ================ Q7 ================ END #" << std::endl;

    // --------- 8 --------
    std::cout << "\n\n# BEGIN ================ Q8 ================ BEGIN #" << std::endl;
    
    // Create Modern CPP Versios of Plane and Pilots

    std::string from_8 = "SCE"; std::cout << "From 'SCE' -> " << std::endl;
    std::string to_8; std::cout << "To where (Input 'PHL' 'ORD' 'EWR': "; std::cin >> to_8;

    std::transform(to_8.begin(), to_8.end(), to_8.begin(), ::toupper);

    auto myModernPlane = std::make_shared<Plane_ModCPP>(from_8, to_8);
    myModernPlane->setVel(400); // Assuming velocity is in miles per hour

    Pilot_ModCPP pilotCharlie("Charlie");
    Pilot_ModCPP pilotDelta("Delta");

    // Assign the plane to the pilots
    pilotCharlie.setMyModernPlane(myModernPlane);
    pilotDelta.setMyModernPlane(nullptr);
    
    // Simulation parameters
    timestep = 9;
    max_iter = 2000;
    bool isCharliePilot = true;
    // Start the simulation
    for (int i = 0; i <= max_iter; i++) {
        int time = timestep * i;

        if (myPlane.getAt_SCE()) {
            std::cout << "\nThe plane " << &myPlane << " is at SCE." << std::endl;
            // Switch pilot
            if (isCharliePilot) {
                pilotCharlie.setMyModernPlane(myModernPlane);
                pilotDelta.setMyModernPlane(nullptr);
                std::cout << "Pilot " << pilotCharlie.getName() << " with certificate number " << &pilotCharlie
                    << " is in control of a plane: " << pilotCharlie.getMyModernPlane() << std::endl;
                std::cout << "Pilot " << pilotDelta.getName() << " with certificate number " << &pilotDelta
                    << " is in control of a plane: " << pilotDelta.getMyModernPlane() << std::endl;

            }
            else {
                pilotCharlie.setMyModernPlane(nullptr);
                pilotDelta.setMyModernPlane(myModernPlane);
                std::cout << "Pilot " << pilotCharlie.getName() << " with certificate number " << &pilotCharlie
                    << " is in control of a plane: " << pilotCharlie.getMyModernPlane() << std::endl;
                std::cout << "Pilot " << pilotDelta.getName() << " with certificate number " << &pilotDelta
                    << " is in control of a plane: " << pilotDelta.getMyModernPlane() << std::endl;
            }
            isCharliePilot = !isCharliePilot; // Toggle the pilot control
            myModernPlane->resetForNextLeg(); // Reset plane's position for the next leg
        }

        // Operate the plane
        myPlane.operate(timestep);
    }

    std::cout << "\n\n# END ================ Q8 ================ END #" << std::endl;

	return 0;
}

