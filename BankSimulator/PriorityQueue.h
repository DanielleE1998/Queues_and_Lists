using namespace std;
#include<iostream>
#include <fstream>

 //
 
template <class ItemType>
struct QueueNode{ 
    ItemType  info; 
    int priority; 
    QueueNode<ItemType> * next;
    }; 

class FullQueue{
};  

class EmptyQueue
{};

  
template <class ItemType>
class PriorityQueue
{
public:
    PriorityQueue();     // Class constructors.
    PriorityQueue(int max);
  
   ~ PriorityQueue();   // Class destructor.
   
    void makeEmpty();   //Removes all elements from the queue. .
 
    bool isEmpty() const; //Returns true if the queue is empty and false otherwise

    bool isFull() const;  //Returns true if the queue is full and false otherwise

/*  Enqueue, input  value and priority
    Adds value at the appropriate position in the queue as determined by the numeric value priority.
    lower numeric values correspond to a higher urgency, 
    so that a task of priority 1 comes before a task with priority 2. 
    If the priority parameter is missing, it defaults to priority 1 
    In case of two items have the  same priority treat them as in FIFO structure. (order or arrival first in first out)
 */
  void Enqueue(ItemType newItem, int priority);

/* Dequeue
   Removes the value at the front of the queue and returns it to the caller. 
   Calling dequeue on an empty queue throws an exception 
*/
ItemType Dequeue();

int GetLength()const;  //Returns the number of elements currently in the queue 

ItemType Peek(); //Returns the value of the most urgent item in the queue without removing it from the queue. 
                 //Calling peek on an empty queue throws an exception
                 
int PeekPriority(); // Returns the priority of the most urgent item in the queue without removing it from the queue. 
                    //Calling peek on an empty queue throws an exception

void PrintQueue(ofstream& file); // Prints Queue items ordered from front to rear

private:
    QueueNode<ItemType>* queueData;
    ItemType* info;
    int Length;
    int Max_Items;
};
