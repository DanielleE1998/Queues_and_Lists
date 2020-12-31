

#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;
class Student{
 public:
  //constructors  
  Student();
  Student(int newID, string newName);
  //setters
  void setID(int newID);
  void setName(string newName);

  //getters
  int getID();
  string getName();

  //overload
  bool operator==(Student a);
  bool operator!=(Student a);
  bool operator<(Student a);
  bool operator>(Student a);
  
 private:
    int studentID;
    string name;
};