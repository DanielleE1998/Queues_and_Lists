#include "Student.h"
#include <string>

Student::Student(){
  this->studentID = 0;
  this->name = "Null";
}

Student::Student(int newID, string newName){
    this->studentID = newID;
    this->name = newName;
}

void Student::setID(int newID){
  this->studentID = newID;}

void Student::setName(string newName){
  this->name = newName;}
  

int Student::getID(){
  return this->studentID;}

string Student::getName(){
  return this->name;}

bool Student::operator== (Student b){
  return ((this->studentID) == (b.studentID)
            &&
            (this->name) == (b.name));}

bool Student::operator!= (Student b){
  return ((this->studentID) != (b.studentID)
           ||
           (this->name) != (b.name));}

bool Student::operator> (Student b){
  return ((this->studentID) > (b.studentID));}

bool Student::operator< (Student b){
  return ((this->studentID) < (b.studentID));}