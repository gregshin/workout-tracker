# workout-tracker
Simple workout tracker prototype to practice inheritance and polymorphism.

## Description
This is a simple CLI program to uses exercise tracking to demonstrate class iheritance and polymorphism in object oriented programming. Each class is separated into its own set of files consisting of header file and class file. 

## Hierarchy
Each type of exercise is respresented as its own class, which specific workouts inheriting from broader class categories.

### Class Inheritance Tree

Base Exercise  
├─ Cardio  
│  ├─ Jog  
│  ├─ Walk  
├─ Strength Training  
│  ├─ Pushups  

### CLI
* WorkoutTracker.h
* WorkoutTracker.cpp

### Base Abstract Class: BaseExercise
* BaseExercise.h
* BaseExercise.cpp

### Derived Abstract Class: Cardio
Inherits from BaseExercise

* Cardio.h
* Cardio.cpp

### Derived Abstract Class: StrengthTraining
Inherits from BaseExercise

* StrengthTraining.h
* StrengthTraining.cpp

### Derived Class: Jog
Inherits from Cardio

* Cardio.h
* Cardio.cpp

### Derived Class: Pushups
Inherits from StrengthTraining

* Pushups.h
* Pushups.cpp

### Derived Class: Walk
Inherits from Cardio

* Walk.h
* Walk.cpp

### Exception Handling
Exception handling is 