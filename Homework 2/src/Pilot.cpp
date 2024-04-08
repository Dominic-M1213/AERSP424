# include <../src/Pilot.h>

std::mutex Pilot::console_mtx;

Pilot::Pilot(int id, ATC& atc) : id(id), atc_control(atc) {}

void Pilot::operateAircraft() {
    log("Aircraft #" + std::to_string(id) + " is approaching.");

    if (atc_control.tryToQueue(id)) {
        while (true) {
            if (atc_control.tryToLand(id)) {
                log("Aircraft #" + std::to_string(id) + " requesting landing.");
                atc_control.land(id); // This blocks until the landing process is complete.
                log("Aircraft #" + std::to_string(id) + " is cleared to land.");
                break;
            }
        }
    }
    else {
        log("Aircraft #" + std::to_string(id) + " redirected to another airport.");
    }
}

void Pilot::log(const std::string& message) {
    std::lock_guard<std::mutex> lock(console_mtx);
    std::cout << message << std::endl;
}