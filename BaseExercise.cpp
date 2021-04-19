#include "BaseExercise.h"

// constructor
BaseExercise::BaseExercise(double time, double lbs)
	: totalBurn{ 0.0 }, timeSpent{ time }, weight{ lbs } {}

// set weight
void BaseExercise::setWeight(double lbs)
{
	weight = lbs;
}
// set name
void BaseExercise::setExerciseName(std::string name)
{
	exerciseName = name;
}
// set total caloric burn
void BaseExercise::setTotalBurn(double burn)
{
	totalBurn = burn;
}
// set time spent
void BaseExercise::setTimeSpent(double time)
{
	timeSpent = time;
}
// set weight
double BaseExercise::getWeight() const
{
	return weight;
}
// get time spent
double BaseExercise::getTimeSpent() const
{
	return timeSpent;
}
// get total caloric burn
double BaseExercise::getTotalBurn() const
{
	return totalBurn;
}
// get exercise name
std::string BaseExercise::getExerciseName() const
{
	return exerciseName;
}