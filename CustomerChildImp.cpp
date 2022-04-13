//*****************************
//                             
// @author Bas, David John
//
//*****************************

#include <iostream>
#include <fstream>
#include <conio.h>
#include <string>
#include <iomanip> 
#include "CustomerChild.h"
using namespace std;

// To rent a movie
void CustomerRent::rent() {
    ifstream read;
    ofstream fout;
    string file_name;
    int num, update, found = 0, found2 = 0;
    char dec;
    read.open("customer.txt");
    
    cout << "\n\t\t\t<< Rent a Video >> " << endl;
    
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
		found = 1;
		
		file_name = "customer-rent" + to_string(ID.front());
    	file_name.append(".txt");
	
		
		break;
        }
        ID.pop();
        customer.pop();
        addr.pop();
	}
	if(found==0){
	    cout << "\n\t\t\tCustomer ID is not exist! " << endl;
	}
	
    
    cout << "\n" << "\t\t\tVideos to rent..." << endl;
    
    do {
    readMovie();
    
    cout << "\n\t\t\tVideo ID: ";
    cin >> num;

    while(!Code.empty()) {
        if(Code.front()==num) {
            cout << "\t\t\tMovie Title: " << Title.front()  << endl;
            cout << "\t\t\tGenre: " << Genre.front()  << endl;
            cout << "\t\t\tProduction: " << Prod.front()  << endl;
            cout << "\t\t\tNumber of Copies: " << --NumCopies.front() << endl;
            cout << "\t\t\tImage: " << MovImg.front()  << endl;
           
            update = NumCopies.front();
            fout << "\n" << Code.front() << "\n" << Title.front();
            fout.open(file_name, ios::app);
            updateMoviesList(num, update);
		
            found2 = 1;
            
            break;
        }else {

        Code.pop_front();
        Title.pop_front();
        Genre.pop_front();
        Prod.pop_front();
        NumCopies.pop_front();
        MovImg.pop_front();
        }

    }
    
    if (found2==0) {
        cout << "\n\t\t\tID is not in the list!" << endl;
    }
    
    fout << "\n" << Code.front() << "\n" << Title.front();
    
    cout << "\n\t\t\tRent another video? ";
    cin >> dec;
    
    if(dec=='N'||dec=='n'){
        fout.close();
        read.close();
        break;
    }
    
    }while(dec=='Y'||dec=='y');
    
    
    cout << "\n\t\tPress <Enter> to continue... ";
    cin.ignore();
    cin.ignore();
    getch();        
}

// To return a movie
void CustomerRent::back(){
    ifstream read;
    ifstream scan;
    ifstream search;
    string file_name;
    int num,found = 0, found2 = 0, update;
    read.open("customer.txt");
    
    cout << "\n\t\t\t<< Return a Video >> " << endl;
    
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
		
		file_name = "customer-rent" + to_string(ID.front()) + ".txt";

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
	
    cout << "\n" << "\t\t\tVideos Rented..." << endl;
    int vidID;
    string movName;
    scan.open(file_name);
    search.open("videos.txt");
      
    if(!scan.is_open()){
        cout << "\n\t\t\tNo videos rented!"<<endl;
    }else {
    readMovie();
    while(!scan.eof()){
        scan >> vidID;
        scan >> movName;
    
        cout << setw(20) << right << "\t\t\tVideo ID: "  << setw(5) << right << vidID << endl;
        
        rentID.push_back(vidID);
        
         rentID.sort();
            if(Code.front()==rentID.front()){

            search >> Code.front();
            search >> Title.front();
            search >> Genre.front();
            search >> Prod.front();
            search >> ++NumCopies.front();
            search >> MovImg.front();
           
            update = NumCopies.front();
            
            updateMoviesList(Code.front(), update);
            found2 = 1;
            }else {
            rentID.pop_front();
            Code.pop_front();
            Title.pop_front();
            Genre.pop_front();
            Prod.pop_front();
            NumCopies.pop_front();
            MovImg.pop_front();
            }
        
        }    
    }
           
    
    remove(file_name.c_str());
    read.close();
    scan.close();
    
    if(found2!=0)
        cout << "\n\t\t\tVideos successfully returned!"<<endl;
        
    cout << "\n\t\tPress <Enter> to continue... ";
    cin.ignore();
    cin.ignore();
    getch(); 
}

// To read all movies list from the .txt file
void CustomerRent::readMovie() {
    ifstream read;
    read.open("video.txt");
    
    int code, numCopies;
    string title, genre, prod, movImg;
    while (!read.eof()) {
        read >> code;
        read >> title;
        read >> genre;
        read >> prod;
        read >> numCopies;
        read >> movImg;


        Code.push_back(code);
        Title.push_back(title);
        Genre.push_back(genre);
        Prod.push_back(prod);
        NumCopies.push_back(numCopies);
        MovImg.push_back(movImg);
    }

    read.close();
}

// To update the list of movies when the user choose
// to rent or return a specific movie
void CustomerRent::updateMoviesList(int ID, int copies) {
        ofstream tempFile;
        tempFile.open("temp.txt", ios::app);
        ifstream read;
        read.open("video.txt");
        
        int vid_id, numCopies;
        string title, genre, movImg, prod;
        while (!read.eof()) {
            read>>vid_id;
            read>>title;
            read>>genre;
            read >> prod;
            read >> numCopies;
            read >> movImg;
            
            if (vid_id == ID) {
                tempFile << "\n" << vid_id;
                tempFile << "\n" << title;
                tempFile << "\n" << genre;
                tempFile << "\n" << prod;
                tempFile << "\n" << copies;
                tempFile << "\n" << movImg;
                
            } else {
                tempFile << "\n" << vid_id;
                tempFile << "\n" << title;
                tempFile << "\n" << genre;
                tempFile << "\n" << prod;
                tempFile << "\n" << numCopies;
                tempFile << "\n" << movImg;
            }
        }
        remove("video.txt");
        rename("temp.txt", "video.txt");
        read.close();
        tempFile.close();
}