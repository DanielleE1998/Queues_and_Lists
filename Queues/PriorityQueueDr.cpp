#include<iostream>
#include<cstdlib>

using namespace std;
// Test driver
#include <iostream>
#include <fstream>
#include <string>
#include "PriorityQueue.cpp"
using namespace std;
void testCharQueue();

int main()
{

    testCharQueue();
    return 0;
}


void testCharQueue()
{
PriorityQueue<char> queue(5);

string command;
ifstream inFile;
ofstream outFile;
inFile.open("inFile.txt");
outFile.open("outFile.txt");
if (!inFile) {
    cout <<"unable to open input stream ";
    exit(0);
}
char itemValue;   // item value to be read from infile.txt
int priority; // priority values to be read from  inFile.txt
//string line;
inFile>> command; 
while (command != "Quit")
    {
    try    
        {
        if (command == "IsEmpty")
            if (queue.isEmpty())
                outFile << "Queue is empty";
            else
                outFile << "Queue is not empty";
                
        else if (command == "IsFull")
            if (queue.isFull())
                outFile << "Queue is full";
            else
                outFile << "Queue is not full";
         
        else if (command == "MakeEmpty")
            queue.makeEmpty();	
            
        else if (command == "GetLength")
            outFile <<"Number of items in the Queue is: "<<queue.GetLength();  
      
        else if (command == "Enqueue")
        {
            inFile >> itemValue;
            inFile >> priority;
            queue.Enqueue(itemValue,priority);
            outFile <<itemValue<<" is Enqueued";
        }
      
        else if (command == "Dequeue")
        {   
            char value = queue.Dequeue();
            outFile <<value<<" was dequeued";

        }
        
        else if (command == "Peek"){
            outFile <<"Front item is "<< queue.Peek();
        }
        else if (command == "PeekPriority"){
            outFile <<"Priority of the front item is "<<queue.PeekPriority();
        }
        
        else if (command == "List")
        {
           queue.PrintQueue(outFile);
        }   

    } // try

    catch(FullQueue e){
        outFile <<"FullQueue exception thrown";
        inFile>> command;
    }
    catch (EmptyQueue e){
        outFile <<"EmptyQueue exception thrown";
        inFile>> command;
    }
            
  outFile << "\n";
  inFile>> command;
  } //end while not quit
}//end testcharqueue
  
 