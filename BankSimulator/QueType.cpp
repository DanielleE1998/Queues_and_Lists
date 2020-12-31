#include<iostream>
#include "QueType.h"

template <class ItemType>
 QueType<ItemType>::QueType(int max)
 {
  maxLength = max + 1;
  front = maxLength - 1;
  rear = maxLength - 1;
  count =0;
  items = new ItemType[maxLength];
}
template <class ItemType>
QueType<ItemType>::QueType()          
{
  maxLength = 501;
  front = maxLength - 1;
  rear = maxLength - 1;
  count =0;
  items = new ItemType[maxLength];
}
template <class ItemType>
QueType<ItemType>::~QueType()         
{
  delete [] items;
}
template <class ItemType>
bool QueType<ItemType>::IsEmpty() 
{
  return (rear == front);
}
template <class ItemType>
bool QueType<ItemType>::IsFull(){
  //return ((rear + 1) % maxLength == front);
  return (count == maxLength-1);
}
template <class ItemType>
void QueType<ItemType>::MakeEmpty()
{
  front = maxLength - 1;
  rear = maxLength - 1;
  count =0;
}

template <class ItemType>
int QueType<ItemType>::getSize()
{ 
    return count;
}
template <class ItemType>
void QueType<ItemType>::Enqueue(ItemType newItem) 
{
  if (IsFull())
    throw FullQueType();
  else
  {
    rear = (rear +1) % maxLength;
    items[rear] = newItem;
    count++;
  }
}
template <class ItemType>
ItemType QueType<ItemType>::Dequeue()
{
  ItemType item;
  if (IsEmpty())
    throw EmptyQueType();
  else
  {
    front = (front + 1) % maxLength;
    item = items[front];
    count--;
  }
  return item;
}

