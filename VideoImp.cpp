//******************************
//                             
// @author Celeste, Curt Russel
//
//******************************

#include <iostream>
#include <fstream>
#include <conio.h>
#include "Video.h"
using namespace std;

// To add movies
void MovieList::insertMovie() {
    List l;
    int code = idGenerate();
    ofstream fout;
    fout.open("video.txt", ios::app);

    cout << "\n\t\t\t<< New Video >> " << endl << endl;

    cout << "\t\t\tVideo ID: ";
    cout << ++code << endl;
    cout << "\t\t\tMovie Title: ";
    getline(cin >> ws, l.title);
    cout << "\t\t\tGenre: ";
    getline(cin >> ws, l.genre);
    cout << "\t\t\tProduction: ";
    getline(cin >> ws, l.prod);
    cout << "\t\t\tNumber of Copies: ";
    cin >> l.numCopies;
    cout << "\t\t\tMovie Image Filename: ";
    getline(cin >> ws, l.movImg);


    fout << "\n" << code << "\n" << l.title << "\n" << l.genre << "\n" <<  l.prod << "\n" << l.numCopies << "\n" << l.movImg;
    fout.close();

    cout << "\n\t\tPress <Enter> to continue... ";
    cin.ignore();
    getch();
}

// To display list of movies
void MovieList::displayMoviesList() {

    readMovie();

    cout << "\n\t\t\t<< Display all Videos >> " << endl << endl;
    
    while(!code_lst.empty()) {
        cout << "\n\t\t\tVideo ID: " << code_lst.front() << endl;
        cout << "\t\t\tMovie Title: " << title_lst.front()  << endl;
        cout << "\t\t\tGenre: " << genre_lst.front()  << endl;
        cout << "\t\t\tProduction: " << prod_lst.front()  << endl;
        cout << "\t\t\tImage: " << movImg_lst.front()  << endl;

        code_lst.pop_front();
        title_lst.pop_front();
        genre_lst.pop_front();
        prod_lst.pop_front();
        movImg_lst.pop_front();

    }
    cin.ignore();
    cout << "\n\t\tPress <Enter> to continue... ";
    cin.ignore();
    getch();
}

// To display the details of specific movie
void MovieList::displayMovie() {
    readMovie();
    int found = 0;
    int num;

    cout << "\n\t\t\t<< Show Video Details >> " << endl;
    cout << "\n\t\t\tVideo ID: ";
    cin >> num;

    while(!code_lst.empty()) {
        if(code_lst.front()==num) {
            cout << "\t\t\tMovie Title: " << title_lst.front()  << endl;
            cout << "\t\t\tGenre: " << genre_lst.front()  << endl;
            cout << "\t\t\tProduction: " << prod_lst.front()  << endl;
            cout << "\t\t\tNumber of Copies: " << numCopies_lst.front() << endl;
            cout << "\t\t\tImage: " << movImg_lst.front()  << endl;

            found = 1;
            break;
        } else {
        code_lst.pop_front();
        title_lst.pop_front();
        genre_lst.pop_front();
        prod_lst.pop_front();
        numCopies_lst.pop_front();
        movImg_lst.pop_front();
        }
    }

    if (found==0) {
        cout << "\n\t\t\tID is not in the list!" << endl;
    }

    cin.ignore();
    cout << "\n\t\tPress <Enter> to continue... ";
    cin.ignore();
    getch();

}

// To check the availability of the movie
void MovieList::checkMovie() {
    readMovie();
    int found = 0;
    int num;

    cout << "\n\t\t\t<< Check Video Availability >> " << endl;
    cout << "\n\t\t\tVideo ID: ";
    cin >> num;

    while(!code_lst.empty()) {
        if(code_lst.front()==num) {
            cout << "\t\t\tMovie Title: " << title_lst.front()  << endl;
            cout << "\t\t\tGenre: " << genre_lst.front()  << endl;
            cout << "\t\t\tProduction: " << prod_lst.front()  << endl;
            cout << "\t\t\tNumber of Copies: " << numCopies_lst.front() << endl;
            if(numCopies_lst.front()==0)
                cout << "\t\t\tAvailability: " << "Not Available "  << endl;
            else
                cout << "\t\t\tAvailability: " << "Available"  << endl;

            found = 1;
            break;
        }else {
        code_lst.pop_front();
        title_lst.pop_front();
        genre_lst.pop_front();
        prod_lst.pop_front();
        numCopies_lst.pop_front();
        }
    
    }

    if (found==0) {
        cout << "\n\t\t\tID is not in the list!" << endl;
    }

    cin.ignore();
    cout << "\n\t\tPress <Enter> to continue... ";
    cin.ignore();
    getch();

}

// To generate movie id from the .txt file
int MovieList::idGenerate() {
    List l;
    ifstream read;
    read.open("video.txt");
    while (!read.eof()) {
        read>>l.code;
        read>>l.title;
        read>>l.genre;
        read>>l.prod;
        read>>l.numCopies;
        read>>l.movImg;
        auto_id.push_back(l.code);
    }
    read.close();
    return auto_id.back();
}

// To read all data from the .txt file
void MovieList::readMovie() {
    List l;
    ifstream read;
    read.open("video.txt");

    while (!read.eof()) {
        read >> l.code;
        read >> l.title;
        read >> l.genre;
        read >> l.prod;
        read >> l.numCopies;
        read >> l.movImg;


        code_lst.push_back(l.code);
        title_lst.push_back(l.title);
        genre_lst.push_back(l.genre);
        prod_lst.push_back(l.prod);
        numCopies_lst.push_back(l.numCopies);
        movImg_lst.push_back(l.movImg);
    }
    
    read.close();
}