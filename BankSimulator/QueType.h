//Queue ADT (Array): C++ Specification

//exceptions
class FullQueType{};  
class EmptyQueType{};  

//typedef char ItemType;
template <class ItemType>
class QueType
{
public:
  //constructors and destructor
  QueType();
  QueType(int max);
  ~QueType();

  //observer
  bool IsEmpty() ;
  bool IsFull() ;

  //transformer
  void MakeEmpty();
  int getSize();
  void Enqueue(ItemType item);
  //void Dequeue(ItemType& item);  >>>>> change to not void
  ItemType Dequeue();

private:
  int front;
  int rear;
  int count;  //>>>>>>>>>>>>>>.add count to track how many entries
  ItemType* items;
  int maxLength;
};



