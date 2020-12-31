using namespace std;
#include<string>

class Customer
{
public:
  //constructors and destructor
  Customer(string n);
  Customer();
  ~Customer();
  
  //getters and setters
  void setName(string n);
  string getName();
  void setArrival(int t);
  int getArrival();
  void setService(int t);
  int getService();
  void setWait(int t);
  int getWait();
  
  private:
  string name;
  int  arrival,service,wait;
};