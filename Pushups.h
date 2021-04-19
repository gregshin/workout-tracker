#pragma once

#include "StrengthTraining.h"

// class definition for pushups. Inherits from StrengthTraining
class Pushups : public StrengthTraining
{
public:
	// constructor definition
	Pushups(double time, double lbs, int reps);

	// override function for calculating total burn
	void calcTotalBurn() override;

	// override procedure for outputting data toString
	virtual std::string toString() override;
private:
};