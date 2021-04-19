#include "Cardio.h"

// constructor for Cardio class
Cardio::Cardio(double time, double dist, double lbs) : BaseExercise(time, lbs) {
	// set distance using setDistance procedure
	setDistance(dist);
}
// set distance procedure
void Cardio::setDistance(double dist)
{
	distance = dist;
}
// set speed procedure
void Cardio::setSpeed(double rate)
{
	speed = rate;
}
// get distance function
double Cardio::getDistance()
{
	return distance;
}
// get speed function
double Cardio::getSpeed()
{
	return speed;
}