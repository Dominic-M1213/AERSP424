# ifndef PILOT_H
# define PILOT_H

// Preprocessor headers
# include <../src/ATC.h>    // already includes necessary headers like iostream, mutex and string
# include <chrono>

// Pilot Class Definition
class Pilot {
private:
    int id;             // Private Pilot ID 
    ATC& atc_control;   // Local ATC Control reference (allows for Pilot to reach out to ATC)
    static std::mutex console_mtx;  // Console Mutex to control the shared resource of the Console itself

public:
    Pilot(int id, ATC& atc);    // Constructor
    void operateAircraft();     // Operation function for main Pilot control
    static void log(const std::string& message);    // Log function for clean console output and control of console
};

# endif // PILOT_H
