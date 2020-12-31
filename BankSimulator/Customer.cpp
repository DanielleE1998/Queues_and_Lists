#include<iostream>
#include "Customer.h"

 Customer::Customer(){
  name = "";
  arrival=0;
  service=0;
  wait =0;
 }
 Customer::Customer(string n)
 {
  name = n;
  arrival=0;
  service=0;
  wait =0;
}


Customer::~Customer()         
{
}

void Customer::setName(string n) {name = n;}
string Customer::getName(){ return name;}

void Customer::setArrival(int t) {arrival = t;}
int Customer::getArrival(){ return arrival;}

void Customer::setService(int t) {service = t;}
int Customer::getService(){ return service;}

void Customer::setWait(int t) {wait = t;}
int Customer::getWait(){ return wait;}