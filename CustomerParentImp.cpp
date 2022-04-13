//*****************************
//                             
// @author Gueco, Gerald
//
//*****************************

#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include <iomanip> 
#include "CustomerParent.h"
using namespace std;

// To add a new customer
void CustomerDetails::add() {
    Customer c;
    int custID = read();
    ofstream fout;
    fout.open("customer.txt", ios::app);
    cout << "\n\t\t\t<< Add New Customer >> " << endl;
    
            cout << "\n\t\t\tCustomer ID: ";
            cout << ++custID << endl;
            cout << "\t\t\tName: ";
            cin.ignore();
            getline(cin, c.name);
            cout << "\t\t\tAddress: ";
            getline(cin, c.address);
            fout << "\n" << custID << "\n" << c.name << "\n" << c.address;
            fout.close();
            cout << "\n\t\tPress <Enter> to continue... ";
            cin.ignore();
            getch();
    
}

// To display the information details of a customer
void CustomerDetails::show() {
    Customer c;
    ifstream read;
    int num, found = 0;
    read.open("customer.txt");
    
    cout << "\n\t\t\t<< Show Customer Details >> " << endl;
    cout << "\n\t\t\tCustomer ID: ";
    cin >> num;
    
    while (read) {
        read >> c.id;
        read >> c.name;
        read >> c.address;
        ID.push(c.id);
        customer.push(c.name);
        addr.push(c.address);
    }

    
    while(!ID.empty()){
        
        if(ID.front()==num){
		cout<<"\t\t\tName: "<<customer.front()<<endl;
		cout<<"\t\t\tAddress: "<<addr.front()<<endl;
		found = 1;
		break;
        }
        ID.pop();
        customer.pop();
        addr.pop();
	}
	if(found==0){
	    cout << "\n\t\t\tCustomer ID is not exist! " << endl;
	}
	
    read.close();
    
    cout << "\n\t\tPress <Enter> to continue... ";
    cin.ignore();
    cin.ignore();
    getch();        
} 

// To print the list of movies rented by customer
void CustomerDetails::printRent() {
    ifstream read;
    ifstream scan;
    string file_name;
    int num,found = 0;
    read.open("customer.txt");
    
    cout << "\n\t\t\t<< Videos Rented by a Customer >> " << endl;
    
    cout << "\n\t\t\tCustomer ID: ";
    cin >> num;

    int id;
    string name, address;
    
    
    while (read) {
        read >> id;
        read >> name;
        read >> address;
        ID.push(id);
        customer.push(name);
        addr.push(address);
    }
    
    while(!ID.empty()){
        
        if(ID.front()==num){
		cout<<"\t\t\tName: "<<customer.front()<<endl;
		cout<<"\t\t\tAddress: "<<addr.front()<<endl;
		
		file_name = "customer-rent" + to_string(ID.front());
	    file_name.append(".txt");

		found = 1;
		
		break;
        }
        ID.pop();
        customer.pop();
        addr.pop();
	}
	if(found==0){
	    cout << "\n\t\t\tCustomer ID is not exist! " << endl;
	}
	
    cout << "\n\t\t\t" << "List of Videos Rented..." << endl;
    
    int vidID;
    string movName;
    scan.open(file_name);
    
    if(!scan.is_open()){
        cout << "\n\t\t\tNo videos rented!"<<endl;
    }else {
    cout<< "\n\t\t\t" << setw(20) << right << "Video ID" << setw(25) << right << "Movie Title" << endl;
    while(!scan.eof()){
        scan >> vidID;
        scan >> movName;
        
        cout << "\t\t\t" << setw(20) << right << vidID << setw(25) << right << movName << endl;
    }
    }
    
    read.close();
    scan.close();
    
    cout << "\n\t\tPress <Enter> to continue... ";
    cin.ignore();
    cin.ignore();
    getch(); 
}

// To read all the customers' data from the .txt file
int CustomerDetails::read(){
    Customer c;
    ifstream read;
    read.open("customer.txt");
    while (!read.eof()) {
        read>>c.id;
        read>>c.name;
        read>>c.address;
        auto_id.push(c.id);
    }
    read.close();
    return auto_id.back();
}

