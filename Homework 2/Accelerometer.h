# ifndef ACCELEROMETER_H
# define ACCELEROMETER_H

# include "Sensor.h"

class Accelerometer : public Sensor {
public:
    Accelerometer() : Sensor("Accelerometer") {} // Constructor

    void gatherData() override {
        std::cout << "Gathering data from " << name << " Sensor." << std::endl;
    }

    void processData() override {
        std::cout << "Processing data from " << name << " Sensor." << std::endl;
    }
};

#endif // ACCELEROMETER_H
