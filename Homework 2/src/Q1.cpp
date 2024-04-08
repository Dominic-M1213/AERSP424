// Q1.cpp
# include <../src/Q1.h>     // Include Q1 headers

void runQ1() {
    std::cout << "Running Q1...\n" << "-----------------------------------------------" << std::endl;

    auto accelerometer = SensorFactory::createSensor("Accelerometer");  // Creates an Accelerometer Sensor
    auto pressureSensor = SensorFactory::createSensor("Pressure");      // Creates an Pressure Sensor
    auto pidoSensor = SensorFactory::createSensor("Pido Tube");         // Creates an Pido Tube Sensor
    auto rando = SensorFactory::createSensor("Rando");                  // Creates a Random (undefined) sensor

    AerospaceControlSystem ctrlSys;     // Defines the ctrl system for the assignment of sensors
    ctrlSys.addSensor(accelerometer);   // Assigns the Accelerometer (is properlly included and managed internally)
    ctrlSys.addSensor(pressureSensor);  // Assigns the Pressure Sensor (is properlly included and managed internally)
    ctrlSys.addSensor(pidoSensor);      // Assigns the Pido Tube (is properlly included and managed internally)
    ctrlSys.addSensor(rando);           // Undefined Sensor is added (rejected and therefore not managed)
    ctrlSys.monitorAndAdjust();         // Manages the known sensor types (excludes the undefined sensor type)

    std::cout << "\nEnding Q1.\n" << "-----------------------------------------------" << std::endl;
}
