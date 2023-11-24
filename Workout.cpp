//Name: Workout.cpp
//Project: CMSC 202 Project 3, Fall 2023
//Author:  Daudi Mwangi
//Date:    10/14/23
//Desc: This file implements the Workout Class.

#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>
#include "Workout.h"
using namespace std;

//Basic class constructor for workout that sets
// head pointers and tail pointers to null and size to 0.
Workout::Workout() {
    m_head = nullptr;
    m_tail = nullptr;
    m_size = 0;
}

//Overloaded constructor that also sets the member variable name.
Workout::Workout(string name) {
    m_head = nullptr;
    m_tail = nullptr;
    m_size = 0;
    m_name = name;
}

//Class Deconstructor that destroys objects of the workout class.
Workout::~Workout(){
    Exercise* curr = m_head;
    while (curr != nullptr){//while the pointer is pointig to somehting
        m_head = curr;
        curr = curr -> GetNext(); // move to the next node.
        delete m_head; // delete the curr node
    }
    m_head = nullptr;
    m_tail = nullptr;
    m_size = 0;
}


//Inserts the given exercise pointer to the end of the linked list
//If there are no elements then set m_head to point to it.
void Workout::InsertEnd(Exercise *newexercise){
  Exercise* temp = m_head;
  if (m_head == nullptr){
    m_head = newexercise;
  }
  else{
    while (temp -> GetNext() != nullptr){
      temp = temp -> GetNext();
    }
    temp -> SetNext(newexercise);
    m_tail = newexercise;
    m_tail -> SetNext(nullptr);
    temp = nullptr;
  }
  m_size++;
}

//functions that returns the name of workout
string Workout::GetName() {return m_name;}

//functions that returns size of workout.
int Workout::GetSize() {return m_size;}

//function that reverses the workout linked list.
// have three temporary pointers and if there are items in the list
// then set the head to be the last and set the other so that
// they are the second and third last. Keep going until there is not
// anything left within the list.
void Workout::ReverseWorkout() {
    Exercise *temp1, *temp2, *temp3;
    if (m_head == nullptr){
        cout << "There are no exercises." << endl;
    }
    else  if (m_head -> GetNext() == nullptr){
      cout << "There is only one exercise" << endl;
    }
    else {
    temp1 = m_head;
    temp2 = temp1 -> GetNext();
    temp3 = temp2 -> GetNext();
    temp1 -> SetNext(nullptr);
    temp2 -> SetNext(temp1);
    while (temp3 != nullptr){
        temp1 = temp2;
        temp2 = temp3;
        temp3 = temp3 -> GetNext();
        temp2 -> SetNext(temp1);
    }
    m_head = temp2;
    }
}

//Function that returns the exercise pointer at the given index in the
// linked list. iterate through the linked list while keeping track and
// once the counter equals what we are looking for return it,
Exercise* Workout::GetData(int nodenum){
    Exercise* temp = m_head;
    int pos = 0;
    while (temp != nullptr){
        if (pos == nodenum){
            return temp;
        }
        pos++;
        temp = temp -> GetNext();
    }
    cout << nodenum << " Is not an index of the list." << endl;
}

// Cout overloaded operator that properly prints out Workout objects in the correct format.
ostream &operator << (ostream &output, Workout &myWorkout){
    output << "Workout for " << myWorkout.m_name << endl;
    output << myWorkout.m_size << " exercises" << endl;
    for (int i = 0; i < myWorkout.GetSize(); i++){
      output << myWorkout.GetData(i) -> GetCategory() << ":";
      output << myWorkout.GetData(i) -> GetName() << "(";
      output << myWorkout.GetData(i) -> GetReps() << "@";
      output << myWorkout.GetData(i) -> GetWeight() << ")" << endl;
    }
    return output;
}




