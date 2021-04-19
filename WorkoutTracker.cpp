#include "WorkoutTracker.h"

// empty constructor
WorkoutTracker::WorkoutTracker(){}

// define starting menu procedure
void WorkoutTracker::startMenu()
{
	// welcome message
	cout << "Welcome to Extracise 1.0! Please choose one of the following options (ctrl-z to exit): \n1. Add an exercise to the tracker\n2. View stats\n3. Delete an exercise" << endl;

	// variable to hold option
	int startOption{ 0 };

	while (cin >> startOption)
	{
		// check for ivalid input
		while (cin.fail())
		{
			cout << "Sorry, that's not a valid entry.\n" << endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << "Please choose one of the following options (ctrl-z to exit): \n1. Add an exercise to the tracker\n2. View stats\n3. Delete an exercise" << endl;
			cin >> startOption;
			cout << endl;
		}

		// switch statement to serve up correct menu
		switch (startOption)
		{
		case 1:
			cout << endl;
			// call newExercise procedure
			newExercise();
			break;
		case 2:
			cout << endl;

			// give error message if tracker is empty
			if (getTrackerLength() == 0)
			{
				cout << "Sorry, your tracker is empty! You should add some workouts to it.\n" << endl;
			} // end if
			// else run the stats procedure
			else
			{
				cout << endl;

				viewStats();
			} // end else 

			break;
		case 3:
			cout << endl;

			if (getTrackerLength() == 0)
			{
				cout << "Sorry, your tracker is empty! You should add some workouts to it.\n" << endl;
			} // end if
			else
			{
				deleteExercise();
			} // end else

			break;
		default:
			// default: not a valid option
			cout << "Sorry, that's not a valid option. Please try again.\n" << endl;
			break;
		} // end switch

		cout << "Would you like to do something else? (ctrl-z to exit)\n1. Add an exercise to the tracker\n2. View stats\n3. Delete an exercise" << endl;
	} // end while
}

// procedure for viewing stats
void WorkoutTracker::viewStats()
{
	// variable to hold user choice and to repeat
	int userChoice{ 0 };
	char repeat{ 'y' };

	// while repeat is y
	while (repeat == 'y')
	{
		// welcome message
		cout << "Let's review your past performance! Which of the following would you like to do?\n1. See your average calories burned\n2. Find out your best workout session\n3. See a rundown of everything" << endl;

		// get user choice
		cin >> userChoice;

		// catch invalid input
		while (cin.fail())
		{
			cout << "Sorry, that's not a valid entry.\n" << endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << "Which of the following would you like to do?\n1. See your average calories burned\n2. Find out your best workout session\n3. See a rundown of everything" << endl;
			cin >> userChoice;
			cout << endl;
		}

		cout << endl;
		
		// init pointer to hold the best exercise
		BaseExercise* best;

		// switch statement for user choice
		switch (userChoice)
		{
		case 1:
			// call getAvgBurn and output
			cout << "You have averaged " << getAvgBurn() << " burned calories per workout\n" << endl;
			break;
		case 2:
			// call getBestWorkout and assign to pointer
			best = getBestWorkout() ;

			// output result
			cout << "Your best workout was when you burned " << best->getTotalBurn() << " calories during this exercise: " << best->getExerciseName() << "\n" << endl;
			break;
		case 3:
			// call getSummary procedure
			getSummary();
			break;
		default:
			// not a valid option default
			cout << "Sorry, that's not a valid option.\n" << endl;
			break;
		}

		// ask user if they want to do something else
		cout << "Would you like to see some other stats? (y or n)" << flush;

		// user input
		cin >> repeat;
		cout << endl;

		// validation for user input
		while (repeat != 'y' && repeat != 'n')
		{
			// error message
			cout << "\nSorry, that's not a valid answer. Please only type y or n\n\n" << "Would you like to see some other stats? (y or n)" << flush;
			cin >> repeat;
		}
	}
}

// procedure to ask user for new exercise
void WorkoutTracker::newExercise()
{
	int userChoice{ 0 };
	char repeat{ 'y' };

	// while repeat is y
	while (repeat == 'y')
	{
		cout << "Which exercise would you like to add to your tracker? (-1 to exit)\n1. Jog\n2. Pushups\n3. Walk" << endl;
		// user input
		cin >> userChoice;

		// input validation
		while (cin.fail())
		{
			cout << "Sorry, I don't recognize that entry. Please only use integers\n" << endl;
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << "Which exercise would you like to add to your tracker?\n1. Jog\n2. Pushups\n" << endl;

			cin >> userChoice;
			cout << endl;
		}

		cout << endl;

		// switch statement for user input
		switch (userChoice)
		{
		case 1:
			// case 1: call newJog procedure
			newJog();
			break;
		case 2:
			// case 2: call newPushup procedure
			newPushup();
			break;
		case 3:
			// case 3: call newWalk procedure
			newWalk();
			break;
		default:
			// default is error statement
			cout << "Sorry, that's not a valid option. Please try again\n" << endl;
			break;
		} // end switch

		// ask user if they want to add a new exercise
		cout << "Would you like to add another exercise to your tracker? (y or n) " << flush;

		cin >> repeat;

		// input validation
		while (repeat != 'y' && repeat != 'n')
		{
			// error message
			cout << "\nSorry, that's not a valid answer. Please only type y or n\n\n" << "Would you like to add another exercise to your tracker? (y or n)" << flush;
			cin >> repeat;
		}

		cout << endl;
	} // end while
}

// get length of vector
int WorkoutTracker::getTrackerLength() const
{
	return tracker.size();
}

// procedure to list all exercises entered
void WorkoutTracker::listExercises()
{
	// vector iterator
	vector<BaseExercise*>::iterator vectItr;

	// iterate through the tracker, and output exercise names
	for (vectItr = tracker.begin(); vectItr < tracker.end(); vectItr++)
	{
		cout << (*vectItr)->getExerciseName() << endl;
	} // end for
}
// function to calculate average calories burned
double WorkoutTracker::getAvgBurn()
{
	// variable to hold total calorie count
	double calorieTotal{ 0 };

	// init vector iterator
	vector<BaseExercise*>::iterator vectItr;

	// iterate through vector and add up calories burned
	for (vectItr = tracker.begin(); vectItr < tracker.end(); vectItr++)
	{
		calorieTotal += (*vectItr)->getTotalBurn();
	} // end for

	// variable to hold average
	double avg{ 0.0 };

	// try/catch block
	try
	{
		avg = calorieTotal / tracker.size();
	}
	catch (DivideByZeroException& divideByZeroException)
	{
		cout << "Exception occurred: " << divideByZeroException.what();
	}
	// return average
	return avg;
}

// function to return best workout
BaseExercise* WorkoutTracker::getBestWorkout()
{
	BaseExercise* bestWorkout{ tracker.at(0) };

	// init vector iterator
	vector<BaseExercise*>::iterator vectItr;

	// iterate through vector and add up calories burned
	for (vectItr = tracker.begin(); vectItr < tracker.end(); vectItr++)
	{
		if ((*vectItr)->getTotalBurn() > bestWorkout->getTotalBurn())
		{
			bestWorkout = (*vectItr);
		} // end if
	} // end for

	// return pointer to the best workout
	return bestWorkout;
}

// definition for getSummary procedure
void WorkoutTracker::getSummary()
{
	// iterator for tracker
	vector<BaseExercise*>::iterator vectItr;

	// iterate trough the tracker and output info on each element
	for (vectItr = tracker.begin(); vectItr < tracker.end(); vectItr++)
	{
		cout << "Exercise " << std::distance(tracker.begin(), vectItr) + 1 << ": " << (*vectItr)->toString();
	}
}

// procedure to delete exercise fromt the tracker
void WorkoutTracker::deleteExercise()
{
	cout << "Please enter the exercise number would you like to delete\n";

	// iterator for tracker
	vector<BaseExercise*>::iterator vectItr;

	// iterate trough the tracker and output info on each element
	for (vectItr = tracker.begin(); vectItr < tracker.end(); vectItr++)
	{
		cout << "Exercise " << std::distance(tracker.begin(), vectItr) + 1 << ": " << (*vectItr)->getExerciseName() << "\n";
	}

	// user input for which element to delete
	int choice{ 0 };
	cout << "Exercise # " << flush;
	cin >> choice;
	cout << endl;

	// catch if input is invalid entry
	while (choice < 1 || choice > getTrackerLength() || cin.fail())
	{
		cout << "Sorry, that's an invalid input. Please try again\n" << endl;
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		cout << "What exercise # would you like to delete? " << flush;

		cin >> choice;
		cout << endl;
	} // end while

	tracker.erase(tracker.begin() + choice - 1);

	cout << "Deletion successful!\n" << endl;
}

// procedure for adding a run to workout
void WorkoutTracker::newJog()
{
	// init variables to hold user input
	double time{ 0.0 };
	double dist{ 0.0 };
	double lbs{ 0.0 };
	
	// intro message
	cout << "Let's talk about your run!\n" << endl;
	
	// user input for time
	cout << "How long did you run for (in minutes)? " << flush;
	cin >> time;

	// catch if input is less than 0 or invalid entry
	while (time <= 0 || cin.fail())
	{
		cout << "Sorry, I don't recognize that entry. Please only use numbers greater than 0\n" << endl;
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		cout << "How long did you run for (in minutes)?" << flush;

		cin >> time;
		cout << endl;
	} // end while

	// user input for distance
	cout << "How far did you run (in miles)? " << flush;
	cin >> dist;

	// catch invalid input
	while (dist <= 0 || cin.fail())
	{
		cout << "Sorry, I don't recognize that entry. Please only use numbers greater than 0\n" << endl;
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		cout << "How far did you run (in miles)? " << flush;

		cin >> dist;
		cout << endl;
	} // end while

	// user input for current weight
	cout << "What is your current weight (in lbs)? " << flush;
	cin >> lbs;

	// catch invalid input
	while (lbs <= 0 || cin.fail())
	{
		cout << "Sorry, I don't recognize that entry. Please only use numbers greater than 0\n" << endl;
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		cout << "What is your current weight (in lbs)? " << flush;

		cin >> lbs;
		cout << endl;
	} // end while

	// add new jog to tracker
	tracker.push_back(new Jog(time, dist, lbs));

	cout << "\nGreat! Your exercise has been added to the tracker\n" << endl;
}
// procedure for adding pushup to workout
void WorkoutTracker::newPushup()
{
	// variables to hold user input
	double time{ 0.0 };
	double lbs{ 0.0 };
	int reps{ 0 };

	// intro message
	cout << "Let's talk about your Pushup set!\n" << endl;

	// user input for time spent
	cout << "How long did you do pushups for (in minutes)? " << flush;
	cin >> time;

	// catch invalid input
	while (time <=0 || cin.fail())
	{
		cout << "Sorry, I don't recognize that entry. Please only use numbers greater than 0\n" << endl;
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		cout << "How long did you do pushups for (in minutes)? " << flush;

		cin >> time;
		cout << endl;
	} // end while

	// user input for weight
	cout << "What is your current weight (in lbs)? " << flush;
	cin >> lbs;

	// catch invalid input
	while (lbs <= 0 || cin.fail())
	{
		cout << "Sorry, I don't recognize that entry. Please only use numbers greater than 0\n" << endl;
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		cout << "What is your current weight (in lbs)? " << flush;

		cin >> lbs;
		cout << endl;
	} // end while

	// user input for # of reps
	cout << "How many pushups did you do? " << flush;
	cin >> reps;

	// catch invalid input
	while (reps <= 0 || cin.fail())
	{
		cout << "Sorry, I don't recognize that entry. Please only use numbers greater than 0\n" << endl;
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		cout << "How many pushups did you do? " << flush;

		cin >> reps;
		cout << endl;
	} // end while
	
	// create new pushup and add to tracker
	tracker.push_back(new Pushups(time, lbs, reps));

	// success message
	cout << "\nGreat! Your exercise has been added to the tracker\n" << endl;
}

// procedure for adding a run to workout
void WorkoutTracker::newWalk()
{
	// init variables to hold user input
	double time{ 0.0 };
	double dist{ 0.0 };
	double lbs{ 0.0 };

	// intro message
	cout << "Let's talk about your walk!\n" << endl;

	// user input for time
	cout << "How long did you walk for (in minutes)? " << flush;
	cin >> time;

	// catch if input is less than 0 or invalid entry
	while (time <= 0 || cin.fail())
	{
		cout << "Sorry, I don't recognize that entry. Please only use numbers greater than 0\n" << endl;
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		cout << "How long did you walk for (in minutes)?" << flush;

		cin >> time;
		cout << endl;
	} // end while

	// user input for distance
	cout << "How far did you walk (in miles)? " << flush;
	cin >> dist;

	// catch invalid input
	while (dist <= 0 || cin.fail())
	{
		cout << "Sorry, I don't recognize that entry. Please only use numbers greater than 0\n" << endl;
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		cout << "How far did you walk (in miles)? " << flush;

		cin >> dist;
		cout << endl;
	} // end while

	// user input for current weight
	cout << "What is your current weight (in lbs)? " << flush;
	cin >> lbs;

	// catch invalid input
	while (lbs <= 0 || cin.fail())
	{
		cout << "Sorry, I don't recognize that entry. Please only use numbers greater than 0\n" << endl;
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		cout << "What is your current weight (in lbs)? " << flush;

		cin >> lbs;
		cout << endl;
	} // end while

	// add new jog to tracker
	tracker.push_back(new Walk(time, dist, lbs));

	cout << "\nGreat! Your exercise has been added to the tracker\n" << endl;
}