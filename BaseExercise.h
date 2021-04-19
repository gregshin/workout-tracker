#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <array>
#include <vector>
#include <sstream>
#include "ExceptionHandling.h"
using std::cout;
using std::cin;
using std::array;
using std::vector;
using std::endl;
using std::flush;

// base exercise abstract class definition
class BaseExercise
{
public:
	// base exercise constructor
	BaseExercise(double time=0.0, double lbs = 0.0);
	
	// procedure to set time spent
	void setTimeSpent(double time);
	// procedure to set weight
	void setWeight(double lbs);
	// procedure to set the total burn
	void setTotalBurn(double burn);
	// procedure to set exerrcise name
	void setExerciseName(std::string name);


	// function to return total burn
	double getTotalBurn() const;
	// function to return weight
	double getWeight() const;
	// function to return time spent
	double getTimeSpent() const;
	// function to return exercise name
	std::string getExerciseName() const;

	// pure virtual function to calculate total burn. Different for each exercise.
	virtual void calcTotalBurn() = 0;

	// pure virtual function to output info
	virtual std::string toString() = 0;
private:
	// private data members
	double totalBurn;
	double timeSpent;
	double weight;
	std::string exerciseName;
};