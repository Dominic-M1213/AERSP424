# ifndef ACCELEROMETER_H
# define ACCELEROMETER_H

# include <../src/Sensor.h>

// Defining a Accelerometer Sensor Class
class Accelerometer : public Sensor {
public:
    Accelerometer() : Sensor("Accelerometer") {} // Constructor

    // Generic function to represent the sensor getting data
    void gatherData() override {
        std::cout << "Gathering data from " << name << " Sensor." << std::endl;
    }

    // Generic function to represent the sensor processing data
    void processData() override {
        std::cout << "Processing data from " << name << " Sensor." << std::endl;
    }
};

#endif // ACCELEROMETER_H
