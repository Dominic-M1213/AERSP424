# ifndef PIDOSENSOR_H
# define PIDOSENSOR_H

# include <../src/Sensor.h>

// Defining a Pido Tube Sensor Class
class PidoSensor : public Sensor {
public:
    PidoSensor() : Sensor("Pido Tube") {} // Constructor

    // Generic function to represent the sensor getting data
    void gatherData() override {
        std::cout << "Gathering data from " << name << " Sensor." << std::endl;
    }

    // Generic function to represent the sensor processing data
    void processData() override {
        std::cout << "Processing data from " << name << " Sensor." << std::endl;
    }
};

#endif // PIDOSENSOR_H
