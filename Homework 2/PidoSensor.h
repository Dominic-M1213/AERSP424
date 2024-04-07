# ifndef PIDOSENSOR_H
# define PIDOSENSOR_H

# include <Sensor.h>

class PidoSensor : public Sensor {
public:
    PidoSensor() : Sensor("Pido Tube") {} // Constructor

    void gatherData() override {
        std::cout << "Gathering data from " << name << " Sensor." << std::endl;
    }

    void processData() override {
        std::cout << "Processing data from " << name << " Sensor." << std::endl;
    }
};

#endif // PIDOSENSOR_H
