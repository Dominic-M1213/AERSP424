// Q1.cpp
# include <../src/Q1.h>

void runQ1() {
    std::cout << "Running Q1...\n" << "-----------------------------------------------" << std::endl;

    auto accelerometer = SensorFactory::createSensor("Accelerometer");
    auto pressureSensor = SensorFactory::createSensor("Pressure");
    auto pidoSensor = SensorFactory::createSensor("Pido Tube");
    auto rando = SensorFactory::createSensor("Rando");

    AerospaceControlSystem ctrlSys;
    ctrlSys.addSensor(accelerometer);
    ctrlSys.addSensor(pressureSensor);
    ctrlSys.addSensor(pidoSensor);
    ctrlSys.addSensor(rando);
    ctrlSys.monitorAndAdjust();

    std::cout << "\nEnding Q1.\n" << "-----------------------------------------------" << std::endl;
}
