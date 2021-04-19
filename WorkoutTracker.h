#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <array>
#include <vector>
using std::cout;
using std::cin;
using std::array;
using std::vector;
using std::endl;
using std::flush;

#include "BaseExercise.h"
#include "Jog.h"
#include "Pushups.h"
#include "Walk.h"

// workout tracker class definition
class WorkoutTracker
{
public:
	// empty constructor
	WorkoutTracker();

	// starting menu
	void startMenu();

	// procedure to displaystats
	void viewStats();

	// procedure to ask user for new exercise
	void newExercise();

	// get length of vector
	int getTrackerLength() const;

	// procedure to list all exercises entered
	void listExercises();

	// function to calculate average calories burned
	double getAvgBurn();

	// procedure to return best workout
	BaseExercise* getBestWorkout();

	// procedure to et summary of all workouts
	void getSummary();

	// procedure to delete a workout
	void deleteExercise();

	// procedure for adding a run to workout
	void newJog();

	// procedure for adding pushup to workout
	void newPushup();

	// procedure for adding walk to workout
	void newWalk();
private:
	// private member to hold exercises
	vector<BaseExercise*> tracker;
};