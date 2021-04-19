#include "StrengthTraining.h"

// class constructor definition for StrengthTraining
StrengthTraining::StrengthTraining(double time, double lbs, int reps) : BaseExercise(time, lbs)
{
	// set number of reps via set procedure
	setNumReps(reps);
}
// define procedure for setting number of reps
void StrengthTraining::setNumReps(int reps)
{
	numReps = reps;
}
// define function for returning number of reps
int StrengthTraining::getNumReps()
{
	return numReps;
}