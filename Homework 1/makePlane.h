#ifndef MAKEPLANE // include guard
#define MAKEPLANE

# include <vector>

class FuelTank {
public:
	double fuelLevel; // lbs
	double fuelMomentArm; // inches
	FuelTank() : fuelLevel(0.0), fuelMomentArm(0.0) {}
	void addFuel(double amount);
	void addFuel(double gallons, double weightPerGallon);
	void drainFuel(double amount);
	void drainFuel(double gallons, double weightPerGallon);
	double getMoment() const;
	double getFuelLevel() const;
	void setFuelMomentArm(double momentArm);
};

class makePlane
{

private:
	double emptyWeight; // lbs
	double emptyWeightMoment; // lbs-inches
	std::vector<double> frontSeatWeights; // lbs
	double frontSeatMomentArm; // inches
	std::vector<double> rearSeatWeights; // lbs
	double rearSeatMomentArm; // inches
	double baggageWeight; // lbs
	double baggageMomentArm; // inches
	FuelTank fuelTank;
	double fuelMomentArm;
	double fuelWeight;

	double maxGrossWeight; // lbs
	double forwardCGLimit; // inches
	double aftCGLimit; // inches

public:
	makePlane();
	~makePlane();

	void setEmptyWeight(double weight, double moment);
	void setFrontSeatParameters(double momentArm, const std::vector<double>& weights);
	void setRearSeatParameters(double momentArm, const std::vector<double>& weights);
	void setBaggageParameters(double weight, double momentArm);
	void setFuelParameters(double gallons, double weightPerGallon, double momentArm);
	void setAircraftLimits(short int MAGW, double forwardCGLimit, double aftCGLimit);

	double getTotalWeight() const;
	double getTotalMoment() const;
	double calculateCG() const;
	bool isWithinLimits() const;
	void FuelRebalance();
	void displayWeightAndBalance() const;

};
#endif