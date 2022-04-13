//*****************************
//                             
// @author Celeste, Curt Russel
//
//*****************************

#pragma once
#include <iostream>
#include <list>

using namespace std;

class MovieList {
  private:
    struct List {
      string title;
      string genre;
      int code;
      int numCopies;
      string movImg;
      string prod;
    };
  list<int> auto_id;
  list<int> code_lst;
  list<string> title_lst;
  list<string> genre_lst;
  list<string> prod_lst;
  list<int> numCopies_lst;
  list<string> movImg_lst;
  
  public:
    void insertMovie();
    void displayMoviesList();
    void displayMovie();
    void checkMovie();
    // Additional operation
    int idGenerate();
    void readMovie();
};