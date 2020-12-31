#include<iostream>
#include<cstdlib>
#include "Student.h"
using namespace std;
// Test driver
#include <iostream>
#include <fstream>
#include <string>
#include "UnsortedList.cpp"
using namespace std;
void testIntegersList();
void testCharactersList();
void testStudentsList();
int main()
{

int datatype;
// Prompt user to enter type of elements 
cout<< "Enter Elements Type\n1 for integer\n2 for character\n3 for Student\n";
cin>> datatype;
switch (datatype)
{ case 1: testIntegersList();
          break;
  case 2: testCharactersList();
           break;
    case 3: testStudentsList();
  break;
 }
//â€¦.append any needed code here
return 0;
}


void testIntegersList()
{
UnsortedList<int> list(5);
string command;
//ifstream inFile;
ofstream outFile;


ifstream inFile;
inFile.open("intcommands2.txt");
outFile.open("outFile.txt");

int number;
 
string line;

//while(inFile.good())
	//{

    inFile>> command; 
    while (command != "Quit")
    {
    try    
        {

        if (command == "IsEmpty")
            if (list.isEmpty())
                outFile << "list is empty";
            else
                outFile << "list is not empty";
                
        else if (command == "PutItem")
        {
            inFile >> number;
            list.putItem(number);
        }
        
        else if (command == "IsFull")
        {
            if (list.isFull())
                outFile << "List is full";
            else
                outFile << "List is not full";
        }
        else if (command == "GetLength")
            outFile << list.getLength();
            
        else if (command == "PrintList")
        {
            outFile << "List Items: ";
            int value;
            for (int index = 0; index < list.getLength(); index++)
            {
                value = list.getAt(index);
                outFile << value << " ";
            }
        }

        else if (command == "DeleteItem")
        {
            inFile >> number;
            try{
                list.deleteItem(number);
            }
            catch (EmptyList e){
                    outFile <<"item is not in the list";
            }
        }
        else if (command == "GetAt")
        {
            inFile >> number;
            if (number >= list.getLength())
                outFile << "index out of range" << " ";
            else{
                int value = list.getAt(number);
                outFile << value << " ";
            }
        }

        else if (command == "MakeEmpty")
        {
            list.makeEmpty();	
        }	
        outFile << "\n";

        // add other cases here to cover all possible commands and any invalid //commandâ€¦.
        inFile>> command;

    } // try
   catch (const std::out_of_range& oor) {
        std::cerr << "Out of Range error: " << oor.what() << '\n';
        inFile>> command;
   }
    catch (DuplicateItem e){
        outFile <<"Entry already exists\n";
        inFile>> command;
    }
    catch(FullList e){
        outFile <<"List is full, insertion failed\n";
        inFile>> command;
    }
    catch (EmptyList e){
        outFile <<"item is not in the list\n";
        inFile>> command;
    }
  
  
    } // while not quit
   // }
} // testIntegersList



void testStudentsList()
{
UnsortedList<Student> list(10);
string command;
ifstream inFile;
ofstream outFile;
inFile.open("studcommands.txt");
outFile.open("outFile.txt");
int number;
string name;
  
//while(inFile.good())
//{
inFile>> command; // read commands from a text file

while (command != "Quit")
{
try
{
if (command == "IsEmpty")
if (list.isEmpty())
outFile << "list is empty";
else
outFile << "list is not empty";

else if (command == "PutItem")
{
inFile >> number;
inFile >> name;
list.putItem(Student(number,name));

}
else if (command == "IsFull")
{
if (list.isFull())
outFile << "List is full";
else
outFile << "List is not full";
}
else if (command == "GetLength")
outFile << list.getLength();

else if (command == "PrintList")
{
outFile << "List Items: ";

for (int index = 0; index < list.getLength(); index++)
{
 Student a = list.getAt(index);
 //value = &(a);
 outFile <<a.getID() << " " << a.getName() << "     ";
}

}



else if (command == "DeleteItem")
{
    inFile >> number;
    inFile >> name;
    list.deleteItem(Student(number,name));
}

else if (command == "GetAt")
{
    inFile >> number;
    if (number >= list.getLength())
        outFile << "index out of range" << " ";
    else{
        Student a = list.getAt(number);
        outFile <<a.getID() << " " << a.getName() << "\n";
    }
    
}

else if (command == "MakeEmpty")
{
 list.makeEmpty();	
}	
outFile << "\n";

// add other cases here to cover all possible commands and any invalid //commandâ€¦.
inFile>> command;

} // try
   catch (const std::out_of_range& oor) {
        std::cerr << "Out of Range error: " << oor.what() << '\n';
        inFile>> command;
   }
    catch (DuplicateItem e){
        outFile <<"Entry already exists\n";
        inFile>> command;
    }
    catch(FullList e){
        outFile <<"List is full, insertion failed\n";
        inFile>> command;
    }
    catch (EmptyList e){
        outFile <<"item is not in the list\n";
        inFile>> command;
    }
 

} // while not quit
//} // while good file
}// end testIntegerList

  
  void testCharactersList(){
// add code to test the characters list, similar to testIntegerslist
 
UnsortedList<char> list(50);
string command;
ifstream inFile;
ofstream outFile;
inFile.open("charcommands.txt");
outFile.open("outFile.txt");

char number;
//while(inFile.good())
//{
inFile>> command; // read commands from a text file

while (command != "Quit")
{
try

{

if (command == "IsEmpty")
if (list.isEmpty())
outFile << "list is empty";
else
outFile << "list is not empty";
else if (command == "PutItem")
{
inFile >> number;
list.putItem(number);
}
else if (command == "IsFull")
{
if (list.isFull())
outFile << "List is full";
else
outFile << "List is not full";
}
else if (command == "GetLength")
outFile << list.getLength();
else if (command == "PrintList")
{
outFile << "List Items: ";
char value;
for (int index = 0; index < list.getLength(); index++)
{
value = list.getAt(index);
outFile << value << " ";
}

}

else if (command == "DeleteItem")
{
inFile >> number;
list.deleteItem(number);
}

else if (command == "GetAt")
{
int numberValue;
inFile >> numberValue;
if (numberValue  >= list.getLength())
 outFile << "index out of range" << " ";
else{
 char charValue = list.getAt(numberValue);
 outFile << charValue << " ";
}
}
else if (command == "MakeEmpty")
{
 
 list.makeEmpty();	
}	

outFile << "\n";	
// add other cases here to cover all possible commands and any invalid //commandâ€¦.
inFile>> command;

} // try

   catch (const std::out_of_range& oor) {
        std::cerr << "Out of Range error: " << oor.what() << '\n';
        inFile>> command;
   }
    catch (DuplicateItem e){
        outFile <<"Entry already exists\n";
        inFile>> command;
    }
    catch(FullList e){
        outFile <<"List is full, insertion failed\n";
        inFile>> command;
    }
    catch (EmptyList e){
        outFile <<"item is not in the list\n";
        inFile>> command;
    }
 
} // while tno quit
 //   } // while good file
  
} // testCharactersList