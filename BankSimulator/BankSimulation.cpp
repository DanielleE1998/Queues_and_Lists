#include <iostream>
#include <fstream>  // file stream
#include <sstream>  //string stream
#include <string>
#include <cstdlib> // to get random
#include <ctime>   // to seed randon
#include "PriorityQueue.cpp"
#include "QueType.cpp"
#include "Customer.h"

using namespace std;

const int MIN_ARRIVAL_TIME = 0;
const int MAX_ARRIVAL_TIME = 25200;
//const int MAX_ARRIVAL_TIME = 420*1;  // do one 7 hour in minute intervals

const int MIN_SERVICE_TIME = 120;
const int MAX_SERVICE_TIME =  480;
//const int MIN_SERVICE_TIME = 2; // 2 minutes
//const int MAX_SERVICE_TIME =  8; // 8 minutes

ofstream outFile;
int numTellers=0;
int numCustomers=0;

double cumulativeWaitTime;

QueType<Customer> setUpCustomerQueue();
void printQueue(Customer c);

int main()
{
QueType<Customer> customerArrivals = setUpCustomerQueue();
try{ 
     QueType<Customer> waitQueue(numCustomers); // create the waiting queue for customers waiting line  
     PriorityQueue<Customer> tellerQueue(numTellers); //create the priority queue for customers at teller window
     Customer c;
     Customer nextCustomer = customerArrivals.Dequeue(); // the first customer in arrivals queue
     int maxTime = MAX_ARRIVAL_TIME;
     int timeSlot;
     for (timeSlot = 0;timeSlot<maxTime;timeSlot++){
          //cout <<"<<<<<<<<<<<<<<we are into time slot "<<timeSlot<<"\n";
          //check if anything can be dequeued from teller queue
          //peek at teller queue to see if ready to dequeue item
          while (!tellerQueue.isEmpty()){
            int exitTime = tellerQueue.PeekPriority();
            if (exitTime == timeSlot){
                //cout << "a teller freed up at time slot "<<exitTime<<"\n";
                tellerQueue.Dequeue();
                if (waitQueue.getSize()>0){ //if any customters waiting
                    c=waitQueue.Dequeue(); // get next customer in line
                    c.setWait(timeSlot - c.getArrival()); // set the wait time 
                    int priority = timeSlot +c.getService();
                    cout <<timeSlot<<" ------ "<<c.getName()<<" enqueue from wait q with exit time = "<<priority<<"\n";
                    tellerQueue.Enqueue(c,priority);
                    printQueue(c);
                }
            }
            else break;
          }
         // now check if any customers have arrived for this time slot 
        while (nextCustomer.getArrival() == timeSlot){
            cout <<timeSlot<<" *** "<< nextCustomer.getName() <<" has arrived at time "<<timeSlot
                <<" with service time = "<<nextCustomer.getService()<<"\n";
            if (tellerQueue.isFull()){
                waitQueue.Enqueue(nextCustomer);    // place customer in wait queue
            }
            else{
                nextCustomer.setWait(0); // this one has 0 wait time
                int priority = timeSlot +nextCustomer.getService(); //figure out exit time to use as priority
                cout <<timeSlot<<" ------ "<<nextCustomer.getName()<<" enqueue with no wait with exit time = "<<priority<<"\n";
                tellerQueue.Enqueue(nextCustomer,priority);
                printQueue(nextCustomer); // log this one
            }
            if (!customerArrivals.IsEmpty()) {
                nextCustomer = customerArrivals.Dequeue(); // get next customer loaded
                //cout <<"next customer is "<<nextCustomer.getName()<<" at arrival time "<<nextCustomer.getArrival()<<"\n";
            }

            else{
                cout <<"done with all customers\n";
                break;
            }
            
        } // end next customer at this time slot
        //cout <<"done checking customers at timeslot "<<timeSlot<<"\n";
        if ( timeSlot == maxTime-1 && waitQueue.getSize()){ 
          maxTime++; //if end of time but still have customers in line, allow  them to wait 7 hours
        }
        //Print your waiting queue and priority queue after every simulated hour
       if ((timeSlot+1) %(3600) == 0 && timeSlot>0){
           cout <<"======== "<<(timeSlot/3600)+1<<"hour queue statuts ========\n";
           cout <<"              wait queue has "<<waitQueue.getSize() <<" customers\n";
           cout <<"            teller queue has "<<tellerQueue.GetLength() <<" customers\n";
           outFile <<"======== "<<(timeSlot/3600)+1<<"hour queue statuts ========\n";
           outFile <<"              wait queue has "<<waitQueue.getSize() <<" customers\n";
           outFile <<"            teller queue has "<<tellerQueue.GetLength() <<" customers\n";
       }
         
     } // end timeslot counter
     cout << "had to stay extra "<<maxTime-MAX_ARRIVAL_TIME<< " to empty wait queue";
     cout <<"cumulative wait time is "<<cumulativeWaitTime<<"\n";
     cout <<"Average waiting time = "<<(cumulativeWaitTime/numCustomers)
          << " seconds  or "<<cumulativeWaitTime/(numCustomers*60)<< "minutes\n";
     outFile <<"Average waiting time = "<<(cumulativeWaitTime/numCustomers)
          << " seconds  or "<<cumulativeWaitTime/(numCustomers*60)<< "minutes\n";
    } // try

    catch(FullQueue e){
        cout <<"FullQueue exception thrown";
    }
    catch (EmptyQueue e){
        cout <<"EmptyQueue exception thrown";
    }
        catch(FullQueType e){
        cout <<"FullQueue exception thrown";
    }
    catch (EmptyQueType e){
        cout <<"EmptyQueue exception thrown";
    }
 return 0;           
}// 
  
  
QueType<Customer> setUpCustomerQueue(){
    

   
    ifstream inFile;

    inFile.open("input.txt");
    outFile.open("outFile.txt");
    if (!inFile) {
        cout <<"unable to open input stream ";
        exit(0);
    }
    string itemName; // item name to be read form input.txt
    inFile>> itemName; 
    if (itemName != "numTellers") {
        cout <<"invalid input file, did not find numTellers ";
    exit(0);
    }
    inFile >> numTellers; // get number of tellers

    inFile>> itemName; 
    if (itemName != "numCustomers") {
        cout <<"invalid input file, did not find numCustomers ";
    exit(0);
    }
    inFile >> numCustomers; // get number of customers
    
    QueType<Customer> customerArrivals(numCustomers); // where to build arrivals queue
    Customer c;
    string name;
    string ignore;
    int arrivalTime;
    int serviceTime;
    int customerCount=0;
    
    // now loop to get customers
    while(1)
    {
        inFile >>name;
        if (inFile.eof()) break;
        inFile >>ignore;
        if (ignore != "arrival"){
            cout <<"bad input file expected 'arrival' and read "<<ignore<<"\n";
            exit(0);
        }
        inFile >>arrivalTime;
        if (arrivalTime<0 || arrivalTime>MAX_ARRIVAL_TIME){
            cout <<"invalid arrival time "<<arrivalTime;
        }
        inFile >>ignore;
        if (ignore != "service"){
            cout <<"bad input file expected 'service' and read "<<ignore<<"\n";
            exit(0);
        }
        inFile >>serviceTime;
        if (serviceTime<MIN_SERVICE_TIME|| serviceTime>MAX_SERVICE_TIME){
            //cout <<"invalid service time "<<serviceTime;
        }
        c.setName(name);
        c.setArrival(arrivalTime);
        c.setService(serviceTime);
        customerArrivals.Enqueue(c);
        customerCount++;
        if (customerCount == numCustomers) break;  // already allocated que with numCustomers, cannot exceed it
    }
    
    if (customerCount == 0){
        cout <<"using randon number generator to create data for "<<numCustomers<<" customers";
        PriorityQueue<int> arrivals(numCustomers);  // create a set of arrival times
        srand(time(0)); // seed the random generator 
        for (int i=0; i<numCustomers;i++){
            int arrivalTime = (rand() % MAX_ARRIVAL_TIME) +1;
            arrivals.Enqueue(arrivalTime,arrivalTime); //arrival time is also the priority value, lowest is first
        } 
        for (int i=0;i<numCustomers;i++){
            std::ostringstream stringStream; // to convert int to string and append to customer name
            stringStream << i+1;
            c.setName("Customer"+stringStream.str());
            c.setArrival(arrivals.Dequeue());
            int serviceTime = MIN_SERVICE_TIME + (rand() % (MAX_SERVICE_TIME-MIN_SERVICE_TIME+1) );
            c.setService(serviceTime);
            customerArrivals.Enqueue(c);
        }
    }
    else if (customerCount != numCustomers){
        cout <<"changing customers count from "<<numCustomers<<" to actual number of customers in input file "<<customerCount<<"\n";
        numCustomers = customerCount;
    }
    cout <<"working with "<<numTellers <<" tellers and "<<numCustomers<<" customers\n";
    return customerArrivals;
}

void printQueue(Customer c){
    cout <<c.getName()<<" wait time " << c.getWait()<<" wait + service time "<<c.getService()+c.getService()<<"\n";
    outFile <<c.getName()<<" wait time " << c.getWait()<<" wait + service time "<<c.getWait()+c.getService()<<"\n";
    cumulativeWaitTime += c.getWait();
}