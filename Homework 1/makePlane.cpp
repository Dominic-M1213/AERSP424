# include <iostream>
# include <numeric>
# include <vector>
# include "makePlane.h"

// FuelTank methods
void FuelTank::addFuel(double amount) {
    fuelLevel += amount;
}
void FuelTank::addFuel(double gallons, double weightPerGallon) {
    double amount = gallons * weightPerGallon;
    fuelLevel += amount;
}

void FuelTank::drainFuel(double amount) {
    if (amount <= fuelLevel) {
        fuelLevel -= amount;
    }
    else {
        std::cerr << "Not enough fuel to drain " << amount << " lbs.\n";
    }
}

void FuelTank::drainFuel(double gallons, double weightPerGallon) {
    double amount = gallons * weightPerGallon;
    if (amount <= fuelLevel) {
        fuelLevel -= amount;
    }
    else {
        std::cerr << "Not enough fuel to drain " << amount << " lbs.\n";
    }
}

double FuelTank::getMoment() const {
    return this->fuelLevel * this->fuelMomentArm;
}

double FuelTank::getFuelLevel() const {
    return this->fuelLevel;
}

void FuelTank::setFuelMomentArm(double momentArm) {
    fuelMomentArm = momentArm;
}

makePlane::makePlane() {
    // Constructur function implementation
    // whenever an object is instantiat from a class
    // the constructor function of the class will be
    // called automatically

    std::cout << "Building Airplane...\n" << std::endl;
    using namespace std;

    double emptyWeight; cout << "Airplane Empty Wieght (pounds): "; cin >> emptyWeight;
    double emptyWeight_M; cout << "Airplane Empty Wieght Moment (pounds-inches): "; cin >> emptyWeight_M;
    short int frontSeats; cout << "No. of Front Seat Occupants: "; cin >> frontSeats;

    vector<double> frontSeats_W;
    {
	    double* TEMP_frontSeats_W = new double[frontSeats];
	    for (int i = 0; i < frontSeats; ++i) {
		    cout << "Occupent Weight for Seat " << i + 1 << ": ";
		    cin >> TEMP_frontSeats_W[i];
	    }

	    // Copy the contents to a std::vector
	    frontSeats_W.assign(TEMP_frontSeats_W, TEMP_frontSeats_W + frontSeats);

	    delete[] TEMP_frontSeats_W; // Dynamic memory is freed here
    } // TEMP_frontSeats_W goes out of scope and is no longer accessible

    double frontSeats_MArm; cout << "Front Seat Moment Arm (inches): "; cin >> frontSeats_MArm;

    short int rearSeats; cout << "No. of Rear Seat Occupants: "; cin >> rearSeats;

    vector<double> rearSeats_W;
    {
	    double* TEMP_rearSeats_W = new double[rearSeats];
	    for (int i = 0; i < frontSeats; ++i) {
		    cout << "Occupent Weight for Seat " << i + 1 << ": ";
		    cin >> TEMP_rearSeats_W[i];
	    }

	    // Copy the contents to a std::vector
	    rearSeats_W.assign(TEMP_rearSeats_W, TEMP_rearSeats_W + frontSeats);

	    delete[] TEMP_rearSeats_W; // Dynamic memory is freed here
    } // TEMP_frontSeats_W goes out of scope and is no longer accessible

    double rearSeats_MArm; cout << "Rear Seat Moment Arm (inches): "; cin >> rearSeats_MArm;

    double fuel; cout << "No. of Gallons of Usable Fuel (pounds): "; cin >> fuel;
    double fuel_W; cout << "Usable Fuel Weights per Gallon(pounds): "; cin >> fuel_W;
    double fuel_MArm; cout << "Fuel Tank Moment Arm (inches): "; cin >> fuel_MArm;
    double bags_W; cout << "Baggage Weight (pounds): "; cin >> bags_W;
    double bags_MArm; cout << "Baggage Moment Arm (inches): "; cin >> bags_MArm;

    // Airplane Design Limits
    short int MAGW = 2950; // Maximum Allowable Gross Weight (pounds)
    double forwardCG_Limit = 82.1; // Forward C.G. limit (inches)
    double aftCG_Limit = 84.7; // Aft C.G. limit (inches)

    cout << "\nAirplane Built" << endl;

    // Constructing subsequint functions
    setEmptyWeight(emptyWeight, emptyWeight_M);
    setFrontSeatParameters(frontSeats_MArm, frontSeats_W);
    setRearSeatParameters(rearSeats_MArm, rearSeats_W);
    setBaggageParameters(bags_W, bags_MArm);
    setFuelParameters(fuel, fuel_W, fuel_MArm);
    setAircraftLimits(MAGW, forwardCG_Limit, aftCG_Limit);
    getTotalWeight();
    getTotalMoment();
    calculateCG();

    displayWeightAndBalance();
    
    if (!isWithinLimits()) {
        cout << "\nRebalancing..." << endl;
        FuelRebalance();
        displayWeightAndBalance();
    }

}
makePlane::~makePlane() {
    std::cout << "\nBuilt Plane Destroyed" << std::endl;
}

void makePlane::setEmptyWeight(double weight, double moment) {
    this->emptyWeight = weight;
    this->emptyWeightMoment = moment;
}

void makePlane::setFrontSeatParameters(double momentArm, const std::vector<double>& weights) {
    this->frontSeatMomentArm = momentArm;
    this->frontSeatWeights = weights;
}

void makePlane::setRearSeatParameters(double momentArm, const std::vector<double>& weights) {
    this->rearSeatMomentArm = momentArm;
    this->rearSeatWeights = weights;
}

void makePlane::setBaggageParameters(double weight, double momentArm) {
    this->baggageWeight = weight;
    this->baggageMomentArm = momentArm;
}

void makePlane::setFuelParameters(double gallons, double weightPerGallon, double momentArm) {
    fuelTank.setFuelMomentArm(momentArm);
    fuelTank.addFuel(gallons, weightPerGallon);
    this->fuelMomentArm = momentArm;
    this->fuelWeight = weightPerGallon;
}

void makePlane::setAircraftLimits(short int MAGW, double forwardCGLimit, double aftCGLimit) {
    this->maxGrossWeight = MAGW;
    this->forwardCGLimit = forwardCGLimit;
    this->aftCGLimit = aftCGLimit;
}

double makePlane::getTotalWeight() const {
    double frontSeatsTotal = std::accumulate(frontSeatWeights.begin(), frontSeatWeights.end(), 0.0);
    double rearSeatsTotal = std::accumulate(rearSeatWeights.begin(), rearSeatWeights.end(), 0.0);
    return emptyWeight + frontSeatsTotal + rearSeatsTotal + baggageWeight + fuelTank.fuelLevel;
}

double makePlane::getTotalMoment() const {
    double frontSeatsMoment = std::accumulate(frontSeatWeights.begin(), frontSeatWeights.end(), 0.0,
        [this](double acc, double w) { return acc + w * frontSeatMomentArm; });
    double rearSeatsMoment = std::accumulate(rearSeatWeights.begin(), rearSeatWeights.end(), 0.0,
        [this](double acc, double w) { return acc + w * rearSeatMomentArm; });
    return emptyWeightMoment + frontSeatsMoment + rearSeatsMoment + (baggageWeight * baggageMomentArm) + fuelTank.getMoment();
}

double makePlane::calculateCG() const {
    return getTotalMoment() / getTotalWeight();
}

bool makePlane::isWithinLimits() const {
    double totalWeight = getTotalWeight();
    double cg = calculateCG();
    return totalWeight <= maxGrossWeight && cg >= forwardCGLimit && cg <= aftCGLimit;
}

void makePlane::FuelRebalance() {
    double currentCG = calculateCG();
    double FoSaftey = 0.1;
    if (calculateCG() < forwardCGLimit) {
        double targetCG = forwardCGLimit + FoSaftey;
        double requiredMomentChange = getTotalWeight() * (targetCG - currentCG);
        double balanceFuel = requiredMomentChange / (fuelMomentArm - targetCG);
        fuelTank.addFuel(balanceFuel);
        std::cout << abs(balanceFuel / fuelWeight) << " gallons of fuel drained." << std::endl;
    }
    else {
        double targetCG = aftCGLimit - FoSaftey;
        double requiredMomentChange = getTotalWeight() * (targetCG - currentCG);
        double balanceFuel = requiredMomentChange / (fuelMomentArm - targetCG);
        fuelTank.drainFuel(balanceFuel);
        std::cout << balanceFuel / fuelWeight << " gallons of fuel added." << std::endl;
    }
}

void makePlane::displayWeightAndBalance() const {
    std::cout << "\nTotal Weight: " << getTotalWeight() << " lbs\n";
    std::cout << "Total Moment: " << getTotalMoment() << " lbs-inches\n";
    std::cout << "C.G. Location: " << calculateCG() << " inches\n";
    std::cout << "Within Design Limits: " << (isWithinLimits() ? "Yes" : "No") << "\n";
}