//Name: Manager.cpp
//Project: CMSC 202 Project 3, Fall 2023
//Author:  Daudi Mwangi
//Date:    10/14/23
//Desc:    This file implements the Manager class.

#include "Manager.h"

#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

//Basic class constructor that takes in a string and sets
// the memeber variable m_fileName to it.
// then calls MainMenu
Manager::Manager(string filename) {
  m_fileName = filename;
  MainMenu();
}


//class deconstructor that deallocates the active memory.
Manager::~Manager(){
  for (int i = 0; i < m_workouts.size(); i++){
    delete m_workouts.at(i);
  }
}

//displays all workouts within the m_workouts vector by using the
// overloaded cout functions of Workout objects.
void Manager::DisplayWorkouts(){
  for (int i = 0; i < m_workouts.size(); i++){
    cout << *m_workouts[i] << endl;
 }
}

//Reads in each line then using substring get the correct data we need.
void Manager::ReadFile(){
  string workout_name, category, exercise_name, tempreps, tempweight, line;
  int reps, weight,comma1, comma2, comma3, comma4,  exercise_count = 0;
  ifstream myfile;
  myfile.open(m_fileName);
  while (getline(myfile, line)){//for each line
    //get the location of all commas so we know where to split.
        comma1 = line.find(';');
        comma2 = line.find(';', comma1 + 1);
        comma3 = line.find(';', comma2 + 1);
        comma4 = line.find(';', comma3 + 1);
	
        workout_name = line.substr(0, comma1);
	
        category = line.substr(comma1 + 1, (comma2 - 1) - comma1);
	
        exercise_name = line.substr(comma2 + 1, (comma3 - 1) - comma2);
	
        tempreps = line.substr(comma3 + 1, (comma4 - 1) - comma3);
	
        tempweight = line.substr(comma4 + 1, (comma4 - line.length()));

	//make sure that the strings we got are now turned into ints.
        reps = stoi(tempreps);
        weight = stoi(tempweight);
	exercise_count++;
	Exercise* exerciseptr = new Exercise(category, exercise_name, reps, weight);
	//if the workout we were given does not exist make a new one.
	if (FindWorkout(workout_name) == -1){
	  Workout* workoutptr = new Workout(workout_name);
	  workoutptr -> InsertEnd(exerciseptr);
	  m_workouts.push_back(workoutptr);
	}
	else{
	  //else just insert the exercise to the existing workout
	  m_workouts[FindWorkout(workout_name)] -> InsertEnd(exerciseptr);
	}
  }
  myfile.close();
  cout << exercise_count << " exercises loaded across " << m_workouts.size() << " workouts." << endl;
}

//Functions that inserts a custom exercise into whatever Workout of choice.
void Manager::InsertNewExercise(){
  string newworkout, exercise_name, category;
  int reps, weight;
  cout << "which workout would you like to insert into?" << endl;
  cin >> newworkout;
  cout << "What is the name of the exercise?" << endl;
  //make sure that getline does not read in the escape character from earlier cin
  cin.ignore();
  getline(cin, exercise_name);
  cout << "What is the category of the exercise?" << endl;
  cin >> category;
  cout << "How many reps are the exercise?" << endl;
  cin >> reps;
  cout << "How heavy are the weights? (in lbs)" << endl;
  cin >> weight;
  Exercise *exerciseptr = new Exercise(category, exercise_name, reps, weight);
  if (FindWorkout(newworkout) == -1){
    cout << "New workout " << newworkout << " was created." << endl;
    Workout *workoutptr = new Workout(newworkout);
    m_workouts.push_back(workoutptr);
    workoutptr -> InsertEnd(exerciseptr);
  }
  else{
    m_workouts[FindWorkout(newworkout)]->InsertEnd(exerciseptr);
  }
}

//function that searches a given workout within the list of already
// existing workouts. compares the given string against each index of the
// vector and if not found return -1. Else return the index.
int Manager::FindWorkout(string workoutname){
  if (m_workouts.size() == 0){
    return -1;
  }
  for (int i = 0; i < m_workouts.size(); i++){
    if (workoutname.compare(m_workouts[i]->GetName()) == 0){
      return i;
    }
  }
  return -1;
}

//Function that prints the Main Menu and also checks the user input and
//does whatever choice they choose to make.
//If they choose 4 then delete all the objects in the active memory and
// clear the list.
void Manager::MainMenu(){
  ReadFile();
  int choice = 0;
  while (choice != 4){
    cout << "What would you like to do?:" << endl;
    cout << "1. Display Workouts" << endl;
    cout << "2. Reverse Workouts" << endl;
    cout << "3. Insert New Exercise" << endl;
    cout << "4. Exit" << endl;
    cin >> choice;
    if (choice < 1 or choice > 4){
      cout << "choose a number between 1 and 4 inclusively" << endl;
    }
    if (choice == 1){
    DisplayWorkouts();
    }
    if (choice == 2){
    ReverseWorkout();
    }
    if (choice == 3){
    InsertNewExercise();
    }
  }
  for (int i = 0; i < m_workouts.size(); i++){
    delete m_workouts[i];
    m_workouts[i] = nullptr;
  }
  cout << "Workouts removed from memory" << endl;
  m_workouts.clear();
  cout << "Deleting Workouts" << endl;
  return;
}

// Reverses the vector of Workout pointers by swapping the first - i term with
// the last - i term. Iterates only half the size of the vector since we do
// not want to swap it into the original positions.
void Manager::ReverseWorkout(){
  Workout *temp;
  for (int i = 0; i < m_workouts.size()/2; i++){
      temp = m_workouts[0 + i];
      m_workouts[0 + i] = m_workouts[m_workouts.size() - 1 - i];
      m_workouts[m_workouts.size() - 1 - i] = temp;
    }
}
