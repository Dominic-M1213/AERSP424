# ifndef PILOT_H
# define PILOT_H

# include <../src/ATC.h>
# include <iostream>
# include <chrono>

class Pilot {
private:
    int id;
    ATC& atc_control;
    static std::mutex console_mtx;

public:
    Pilot(int id, ATC& atc);
    void operateAircraft();
    static void log(const std::string& message);
};

# endif // PILOT_H
