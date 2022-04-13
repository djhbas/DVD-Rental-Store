//*****************************
//                             
// @author Bas, David John
//
//*****************************

#pragma once
#include <iostream>
#include <list>
#include <queue>

using namespace std;

class CustomerRent {
  private:
    struct Node {
      int vid_id;
    };
    queue<string> customer;
    queue<string> addr;
    queue<int> ID;
    list<int> rentID;
    list<int> Code;
    list<string> Title;
    list<string> Genre;
    list<string> Prod;
    list<int> NumCopies;
    list<string> MovImg;

  public:
    void rent();
    void back();
    // additional operation
    void readMovie();
    void updateMoviesList(int,int);
};