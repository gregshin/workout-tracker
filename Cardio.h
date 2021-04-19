#pragma once

#include "BaseExercise.h"

// abstract class definition for Cardio. Inherits from BaseExercise
class Cardio : public BaseExercise
{
public:
	// Cardio class constructor
	Cardio(double time, double dist, double lbs);
	
	// procedure to set distance
	void setDistance(double dist);
	// procedure to set speed
	void setSpeed(double rate);

	// function to return distance
	double getDistance();
	// function to return speed
	double getSpeed();

	// virtual fuction for calculating rate
	virtual void calcSpeed() = 0;
private:
	// provate data memebers
	double distance;
	double speed;
};