# ifndef SENSOR_H
# define SENSOR_H

# include <iostream>
# include <string>

// Sensor Class Definition
class Sensor {
protected:
    std::string name; // Name of the sensor for printing purposes

public:
    Sensor(const std::string& name) : name(name) {} // Constructor to set the sensor's name
    virtual ~Sensor() {} // Virtual destructor

    // Pure virtual functions
    virtual void gatherData() = 0;
    virtual void processData() = 0;
};

# endif // SENSOR_H