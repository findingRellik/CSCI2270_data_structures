//Austin Metzner, Assignment 6, Yang Li
#include <iostream>
#include "MovieTree.h"
#include <fstream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main(int argc, char *argv[])
{
    //MovieTree theTree;
    MovieTree *theTree = new MovieTree;

    ifstream inFile;
    inFile.open(argv[1]);
    if(inFile.fail()){
        cout<<"The file was not successfully opened"<<endl;
    }
//Now to read the file and Build the tree
    string title;
    int rank, year, quantity;
    string movieInfo;
    string token;

    while(getline(inFile, movieInfo)){//Reads Lines
        istringstream ss(movieInfo);
        int counter = 0;
        while(getline(ss, token, ',')){//Splits lines by comma
            if(counter == 0){
                rank = atoi(token.c_str());
                counter++;
                continue;
            }
            if(counter == 1){
                title = token;
                counter++;
                continue;
            }
            if(counter == 2){
                year = atoi(token.c_str());
                counter++;
                continue;
            }
            if(counter == 3){
                quantity = atoi(token.c_str());
                //counter = 0;
                //continue;
            }
            theTree->addMovieNode(rank, title, year, quantity); //Add node to existing tree
            counter = 0;//Reset counter for next movie
        }
    }
    inFile.close();

    string userInput;
    while(userInput != "4"){
        cout<<"======Main Menu======"<<endl;
        cout<<"1. Find a movie"<<endl;
        cout<<"2. Rent a movie"<<endl;
        cout<<"3. Print the inventory"<<endl;
        cout<<"4. Quit"<<endl;

        getline(cin,userInput);
//OPTION 1 find movie
        if(userInput == "1"){
            cout<<"Enter title:"<<endl;
            getline(cin,userInput);
            theTree->findMovie(userInput);
        }
//OPTION 2 rent movie
        else if(userInput == "2"){
            cout<<"Enter title:"<<endl;
            getline(cin,userInput);
            theTree->rentMovie(userInput);
        }
//OPTION 3 print movie list
        else if(userInput == "3"){
            theTree->printMovieInventory();
        }
    }
    cout<<"Goodbye!"<<endl;
    delete theTree;

    return 0;
}
