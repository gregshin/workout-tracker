#include "Jog.h"

// class constructor definiton for Jog
Jog::Jog(double time, double dist, double lbs) : Cardio(time, dist, lbs) {
	setExerciseName("Jog");
	calcSpeed();
	calcTotalBurn();
}
// how to calculate total burn for Jog
void Jog::calcTotalBurn()
{
	double total{ 0 };

	// total burn is calculated via MET formula
	try
	{
		total = getTimeSpent() * (8 * 3.5 * (getWeight() * 0.45359237)) / 200;
	}
	// catch divide by zero exception
	catch (DivideByZeroException& divideByZeroException)
	{
		cout << "Exception occurred: " << divideByZeroException.what();
	}

	setTotalBurn(total);
}
// procedure to calculate speed from distance and time
void Jog::calcSpeed()
{
	double rate{ 0 };
	try 
	{
		rate = getDistance() / (getTimeSpent() / 60);
	}
	// catch divide by zero exception
	catch (DivideByZeroException& divideByZeroException)
	{
		cout << "Exception occurred: " << divideByZeroException.what();
	}
	
	setSpeed(rate);
}
// procedure to output data as string
std::string Jog::toString()
{
	std::ostringstream output;

	output << std::fixed << std::setprecision(2);
	output << getExerciseName() << "\nDistance traveled: " << getDistance() << " miles in " << getTimeSpent() << " minutes.\nAverage speed: " << getSpeed() << " miles/hour\nCalories burned: " << getTotalBurn() << "\n" << endl;

	return output.str();
}