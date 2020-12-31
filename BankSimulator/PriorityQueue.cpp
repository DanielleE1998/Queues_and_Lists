#include "PriorityQueue.h"
#include <iostream>
#include <fstream>
// Class constructor
template <class ItemType>
PriorityQueue<ItemType>::PriorityQueue(int max){
  Length = 0;
  queueData = NULL;
  Max_Items= max;
}

// Class destructor
template <class ItemType>
    PriorityQueue<ItemType>::~PriorityQueue(){         
    makeEmpty();
 }

template <class ItemType>
void PriorityQueue<ItemType>::makeEmpty()
{
    QueueNode<ItemType> * currentLocation = new QueueNode<ItemType>; 
    QueueNode<ItemType> * nextLocation = new QueueNode<ItemType>; 
    currentLocation = queueData; //head pointer
    while (currentLocation != NULL)  
    {  
        nextLocation = currentLocation->next;  
        delete(currentLocation);  
        currentLocation = nextLocation;  
    } 
    queueData = NULL;
    Length =0;
}

template <class ItemType>
bool PriorityQueue<ItemType>::isEmpty() const 
{
    return  (Length == 0); // Returns true if the queue is empty; false otherwise.
}

template <class ItemType>
bool PriorityQueue<ItemType>::isFull() const
{
    return (Length == Max_Items); // Returns true if the queue is full; false otherwise.
}

template <class ItemType>
void PriorityQueue<ItemType>::Enqueue(ItemType newItem,int priority){
  QueueNode<ItemType>* location = new QueueNode<ItemType>;
  QueueNode<ItemType>* prevLocation = new QueueNode<ItemType>;
  QueueNode<ItemType>* newNode = new QueueNode<ItemType>;
  newNode->info = newItem;
  newNode->priority=priority;
  newNode->next = NULL;
  if (queueData == NULL){
    queueData = newNode;
    Length++;
  }
  else{
    location = queueData; // head pointer
    prevLocation=NULL;
    int counter =0;
    while (location != NULL && counter <Length){
      counter++;
       //find position for newNode
      if(newNode->priority < location->priority) {
          //cout <<"found insert point at node with item "<<location->info<<"priority "<<location->priority<<"\n";
          break;
      }
      prevLocation = location;
      location=location->next;
    }//end of insert location search
    
    // need to determine if inserting at beginning or not
    if (location==queueData){
        //insert at beginning
        newNode->next=queueData;  // new node points to current first node
        queueData = newNode;       // new node becomes head
    }
    else{
           //insert in the middle
          newNode->next = prevLocation->next;
          prevLocation->next=newNode; 
    }
    Length++;
  }
  
  // for test print queue to see what we have
  /*
  QueueNode<ItemType>* ptr = queueData;
  cout <<"after insert list contains:\n";
  while (ptr!=NULL){
    cout << '\n' << ptr->info<<" with priority "<<ptr->priority;
    ptr = ptr->next;
  }
  delete ptr;
  */
}

template <class ItemType>
int PriorityQueue<ItemType>::GetLength() const
// Returns the number of items in the List
{
return Length;
}

template <class ItemType>
ItemType PriorityQueue<ItemType>::Dequeue(){
  if(isEmpty()) throw (EmptyQueue());
  QueueNode<ItemType>* location = queueData; // node to be selected is the first node
  ItemType item = location->info;
  queueData = location->next;  // advance head pointer to next item
  Length --;
  return item;
}

template <class ItemType>
ItemType PriorityQueue<ItemType>::Peek(){
  if(isEmpty()) throw (EmptyQueue());
  QueueNode<ItemType>* location = queueData; // node to be selected is the first node
  return location->info;
}

template <class ItemType>
int PriorityQueue<ItemType>::PeekPriority(){
  if(isEmpty()) throw (EmptyQueue());
  QueueNode<ItemType>* location = queueData; // node to be selected is the first node
  return location->priority;
}
template <class ItemType>
void PriorityQueue<ItemType>::PrintQueue(ofstream& outFile){
  outFile << "Queue:";
  QueueNode<ItemType>* ptr = queueData;
  while (ptr!=NULL){
    outFile << " "<<ptr->info;
    ptr = ptr->next;
  }
  delete ptr;
}
 


