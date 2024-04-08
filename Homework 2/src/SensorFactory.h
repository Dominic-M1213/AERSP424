# ifndef SENSORFACTORY_H
# define SENSORFACTORY_H

# include <iostream>
# include <string>
# include <memory>
# include <../src/Sensor.h>
# include <../src/SensorTypes.h>

// Sensor Factory Class Definition
class SensorFactory {

public:
    std::string name; // Name of the sensor for printing purposes
    static std::unique_ptr<Sensor> createSensor(const std::string& type) {      // Defining the types of sensors
        if (type == "Accelerometer") return std::make_unique<Accelerometer>();  // Allows Accelerometers to be created
        else if (type == "Pressure") return std::make_unique<PressureSensor>(); // Allows Pressure Sensors to be created
        else if (type == "Pido Tube") return std::make_unique<PidoSensor>();    // Allows Pido Tubes to be created
        else return nullptr;    // Returns nullptr if the sensor is not compatible (some random undefined sensor)
    };
};

# endif // SENSORFACTORY_H