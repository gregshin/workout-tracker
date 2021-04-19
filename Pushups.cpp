#include "Pushups.h"

// push up contructor
Pushups::Pushups(double time, double lbs, int reps) : StrengthTraining(time, lbs, reps)
{
	// set name on construction
	setExerciseName("Pushups");
	// calc total burn
	calcTotalBurn();
}
// how to calculate total burn
void Pushups::calcTotalBurn()
{
	double burn{ 8.56 * getTimeSpent() };
	
	setTotalBurn(burn);
}
// override function to output object data as a string
std::string Pushups::toString()
{
	std::ostringstream output;

	output << std::fixed << std::setprecision(2);
	output << getExerciseName() << "\nYou did: " << getNumReps() << " in " << getTimeSpent() << " minutes.\nCalories burned: " << getTotalBurn() << "\n" << endl;

	return output.str();
}