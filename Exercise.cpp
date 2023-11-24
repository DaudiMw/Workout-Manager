//Name: Exercise.cpp
//Project: CMSC 202 Project 3, Fall 2023
//Author:  Daudi Mwangi
//Date:    10/14/23
//Desc: This file implements the Exercise Class.

#include <iostream>
#include <string>
#include "Exercise.h"
using namespace std;

// Basic constructor
Exercise::Exercise(){}

//Overloaded constructo that assigns the member variables to the
// given values.
Exercise::Exercise(string category, string name, int reps, int weight){
    m_category = category;
    m_name = name;
    m_reps = reps;
    m_weight =  weight;
}

//returns category
string Exercise::GetCategory() {return m_category;}

//returns name
string Exercise::GetName() {return m_name;}

//returns reps
int Exercise::GetReps() {return m_reps;}

//returns weight
int Exercise::GetWeight() {return m_weight;}

//returns the next node of the linked list.
Exercise* Exercise::GetNext() {return m_next;}

//sets the category
void Exercise::SetCategory(string category) {m_category = category;}

//sets the name
void Exercise::SetName(string name) {m_name = name;}

//sets the next node of the linked list to a given pointer.
void Exercise::SetNext(Exercise* next) {m_next = next;}

//sets the reps
void Exercise::SetReps(int reps) {m_reps = reps;}

//sets the weight
void Exercise::SetWeight(int weight) {m_weight = weight;}
