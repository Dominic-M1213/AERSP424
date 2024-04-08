# ifndef PRESSURESENSOR_H
# define PRESSURESENSOR_H

# include <../src/Sensor.h>

class PressureSensor : public Sensor {
public:
    PressureSensor() : Sensor("Pressure") {} // Constructor

    void gatherData() override {
        std::cout << "Gathering data from " << name << " Sensor." << std::endl;
    }

    void processData() override {
        std::cout << "Processing data from " << name << " Sensor." << std::endl;
    }
};

#endif // PRESSURESENSOR_H
