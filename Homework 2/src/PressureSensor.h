# ifndef PRESSURESENSOR_H
# define PRESSURESENSOR_H

# include <../src/Sensor.h> 

// Defining a Pressure Sensor Class
class PressureSensor : public Sensor {
public:
    PressureSensor() : Sensor("Pressure") {} // Constructor

    // Generic function to represent the sensor getting data
    void gatherData() override {
        std::cout << "Gathering data from " << name << " Sensor." << std::endl;
    }

    // Generic function to represent the sensor processing data
    void processData() override {
        std::cout << "Processing data from " << name << " Sensor." << std::endl;
    }
};

#endif // PRESSURESENSOR_H
