#pragma once

#include "BaseExercise.h"

// abstract class definition for StrengthTraining. Inherits from BaseExercise
class StrengthTraining : public BaseExercise
{
public:
	// StrengthTraining constructor
	StrengthTraining(double time, double lbs, int reps);

	// procedure to set number of reps
	void setNumReps(int reps);

	// function to return number of reps
	int getNumReps();

private:
	int numReps;
};