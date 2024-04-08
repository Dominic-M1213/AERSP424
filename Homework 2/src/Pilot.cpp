# include <../src/Pilot.h>

// a shared mutex for the console to syncronize the console outputs amongst pilots
std::mutex Pilot::console_mtx;

// Pilot class constructor
Pilot::Pilot(int id, ATC& atc) : id(id), atc_control(atc) {}

// Operator function that contains the logic of contacting the ATC and controlling
// The aircraft in different situations.
void Pilot::operateAircraft() {
    // general statement declaring an approach
    log("Aircraft #" + std::to_string(id) + " is approaching.");

    // checks if the airplane can enter the airspace
    if (atc_control.tryToQueue(id)) {
        while (true) {
            // Once in the airspace, the pilot will indefinetly wait its turn until landed
            if (atc_control.tryToConnect(id)) {
                // Once in contact to land, the Pilot can request landing clearance
                log("Aircraft #" + std::to_string(id) + " requesting landing.");
                // askes for landing clearance
                atc_control.land(id); // This blocks until the landing process is complete.
                log("Aircraft #" + std::to_string(id) + " is cleared to land.");
                // break loop because were landed
                break;
            }
        }
    }
    else {
        // Since queue is full, redirect to another airport.
        log("Airspace full. Aircraft #" + std::to_string(id) + " redirected to another airport.");
    }
}

// Function to cleanly control the console_mtx and control the outputs to console
// rather than having the same two lines dirty up the code.
void Pilot::log(const std::string& message) {
    std::lock_guard<std::mutex> lock(console_mtx);
    std::cout << message << std::endl;
}