#pragma once

#include "Cardio.h"

// class definition for jog. Inherits from Cardio
class Jog : public Cardio
{
public:
	// jog constructor
	Jog(double time, double dist, double lbs);

	// override procedure for calculating total burn
	virtual void calcTotalBurn() override;

	// override procedure for calculating rate
	virtual void calcSpeed() override;

	// override procedure for outputting data toString
	virtual std::string toString() override;
private:
};