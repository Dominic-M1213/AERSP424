# ifndef AEROSPACECONTROLSTYSTEM_H
# define AEROSPACECONTROLSTYSTEM_H

# include <memory>
# include <vector>
# include "Sensor.h"

class AerospaceControlSystem {
private:
    std::vector<std::unique_ptr<Sensor>> sensors;

public:
    // adding sensors
    void addSensor(std::unique_ptr<Sensor>& sensor) {
        if (sensor) {
            sensors.push_back(std::move(sensor)); // Transfering Ownership of the Sensor to the CS
        }
        else if (!sensor) {
            std::cout << "Sensor type not supported.\n" << std::endl;
        }
        else std::cout << "Sensor failed to be connected to system." << std::endl;
    };

    // iterates through all sensors, gathering/processing data to adjust control
    void monitorAndAdjust() {
        
        for (auto& sensor : sensors) {
            sensor->gatherData();
            sensor->processData();
            std::cout << "Adjusting controls based on sensor data.\n" << std::endl;
        }
        
    };
};

# endif // AEROSPACECONTROLSTYSTEM_H