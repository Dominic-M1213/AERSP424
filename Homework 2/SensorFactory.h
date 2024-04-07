# ifndef SENSORFACTORY_H
# define SENSORFACTORY_H

# include <iostream>
# include <string>
# include <memory>
# include "Sensor.h"
# include "SensorTypes.h"

class SensorFactory {

public:
    std::string name; // Name of the sensor for printing purposes
    static std::unique_ptr<Sensor> createSensor(const std::string& type) {
        if (type == "Accelerometer") return std::make_unique<Accelerometer>();
        else if (type == "Pressure") return std::make_unique<PressureSensor>();
        else if (type == "Pido Tube") return std::make_unique<PidoSensor>();
        else return nullptr;
    };
};

# endif // SENSORFACTORY_H