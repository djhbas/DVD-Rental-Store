//*****************************
//                             
// @author Gueco, Gerald
//
//*****************************

#pragma once
#include <iostream>
#include <queue> 

using namespace std;

class CustomerDetails {
  private:
    struct Customer {
      int id;
      string name;
      string address;
    };
    queue<string> customer;
    queue<string> addr;
    queue<int> ID;
    queue<int> auto_id;
    
  public:
    void add();
    void show();
    void printRent();
    // Additional operation
    int read();
    
};