//***********************************
//
// @author Celeste, Curt Russel
// @author Gueco, Gerald
// @author Bas, David John
//
//***********************************

#include <iostream>
#include "Video.h"
#include "CustomerParent.h"
#include "CustomerChild.h"

using namespace std;


int menu();
void customerMaintenance();

int main() {
    
    MovieList list;        
    CustomerRent Rent;
    string title;
    string genre;
    int numCopies;
    string movImg;
    string prod;

  int ch;

  do {
    ch = menu();

    switch(ch){
   
      case 1:
        system("clear");
        
        list.insertMovie();
        
      break;
    
      case 2:
        system("clear");
        
        Rent.rent();
        
      break;
    
      case 3:
        system("clear");
        Rent.back();
        
      break;
    
      case 4:
        system("clear");
        
        list.displayMovie();
        
      break;
      
      case 5:
        system("clear");
        
        list.displayMoviesList();
        
      break;
      
      case 6:
        system("clear");
      
        list.checkMovie();
        
        break;
      
      case 7:
        customerMaintenance();
        
      break;
    
      case 8:
        system("clear");
        cout << "Goodbye! Thank you for coming " << endl;
        exit(0);
      }

  } while (ch <= 8);
      cout << "\t\t\tInvalid Input!" << endl;
}

int menu() {
  int ch;
  
  system("clear");
  cout <<"\n\t\t\t============================================" << endl;
  cout <<"\t\t\t|            ** Movie Store **             |" << endl;
  cout <<"\t\t\t============================================" << endl;
  cout << "\t\t\t           [1] New Video              " << endl;
  cout << "\t\t\t           [2] Rent a Video           " << endl;
  cout << "\t\t\t           [3] Return a Video         "  << endl;
  cout << "\t\t\t           [4] Show Video Details     " << endl;
  cout << "\t\t\t           [5] Display all Videos     " << endl;
  cout << "\t\t\t           [6] Check Video Availability" << endl;
  cout << "\t\t\t           [7] Customer Maintenance   " << endl;
  cout << "\t\t\t           [8] Exit Program           " << endl << endl;
  cout << "\t\t\tEnter Choice: ";
  cin >> ch;
  cout << endl;
  return (ch);
}
void customerMaintenance() {
  CustomerDetails customer;
  
  string name, address;
  int ch;
  int id;
  
  system("clear");
 cout <<"\n\t\t\t============================================" << endl;
  cout <<"\t\t\t|          ** Customer Maintenance **      |" << endl;
  cout <<"\t\t\t============================================" << endl;
  cout << "\t\t\t         [1] Add New Customer              " << endl;
  cout << "\t\t\t         [2] Show Customer Details         " << endl;
  cout << "\t\t\t         [3] List of Videos Rented by Customer" << endl << endl;
  cout << "\t\t\tEnter Choice: ";
  cin >> ch;
    switch(ch){
        case 1: 
            customer.add();
           
        break;
        
        case 2:
            customer.show();
           
        break;
        
        case 3:
            customer.printRent();
            
        break;
    }
    
}