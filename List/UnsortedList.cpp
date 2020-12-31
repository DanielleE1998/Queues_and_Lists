#include<iostream>
using namespace std;
#include "UnsortedList.h"


template <class ItemType>
UnsortedList<ItemType>::UnsortedList(int max)
// default argument constructor
// Post: Max_Itemms and Length have been initialized.
// The array to hold the queue elements has been allocated.
{
  //max = 50;
  Max_Items= max;
  Length=0;
  info= new ItemType[Max_Items];
}

template <class ItemType>
UnsortedList<ItemType>::~UnsortedList()         // Class destructor
{
  delete [] info;
}

template <class ItemType>

void UnsortedList<ItemType>::makeEmpty()
// Post: Length has been reset to the empty state.
{
  Length=0;
}

template <class ItemType>
bool UnsortedList<ItemType>::isEmpty() const
// Returns true if the List is empty; false otherwise.
{
if (Length == 0)
return true;
else
return false;
 
}

template <class ItemType>
bool UnsortedList<ItemType>::isFull() const
// Returns true if the List is full; false otherwise.
{
if (Length == Max_Items)
    return true;
else
    return false;
//

}

template <class ItemType>
void UnsortedList<ItemType>::putItem(ItemType newItem)
// Post: If list is not full) newItem is at the end of the list;
//       otherwise a FullList exception is thrown.  
{
if (isFull()){
    throw FullList();
}
else {
    if (findIndex(newItem) != -1)
       throw DuplicateItem();
    else
        {
        info[Length]= newItem;
        Length++;
        }
    }
}
template <class ItemType>
int UnsortedList<ItemType>::findIndex(ItemType item) const
// Returns true if the List is empty; false otherwise.
{
for (int i = 0; i < Length; i++)
{
if (info[i] == item)
return i;
}
return -1;
//
}
template <class ItemType>

int UnsortedList<ItemType>::getLength() const
// Returns the number of items in the List
{
return Length;
}

template <class ItemType>
ItemType UnsortedList<ItemType>::getAt(int index)
{
    
if (index >=0 && index < Length)
   return info[index];
else
    throw std::out_of_range ("index out of range");
}


template <class ItemType>
void UnsortedList<ItemType>::deleteItem(ItemType item){
  int index= findIndex(item);
    if (index==-1)
      throw EmptyList();
    else{
      Length--;
      for (int i = index; i < Length;i++){
        info[i]= info[i+1];
      }
    }
}