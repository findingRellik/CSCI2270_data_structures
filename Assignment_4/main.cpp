//Assignment 4, Austin Metzner, Yang
#include <iostream>
#include <fstream>
#include "CommunicationNetwork.h"

using namespace std;

int main()
{

    string userInput;
    CommunicationNetwork *run = new CommunicationNetwork;//instance of Communication network
    City *head = new City;
//Unless user exits with 5, program will keep running
    while(userInput != "7"){
        cout<<"======Main Menu======"<<endl;
        cout<<"1. Build Network"<<endl;
        cout<<"2. Print Network Path"<<endl;
        cout<<"3. Transmit Message Coast-To-Coast-To-Coast"<<endl;
        cout<<"4. Add City"<<endl;
        cout<<"5. Delete City"<<endl;
        cout<<"6. Clear Network"<<endl;
        cout<<"7. Quit"<<endl;

        getline(cin,userInput);
//OPTION 1 build network
        if(userInput == "1"){
            run->buildNetwork();
        }
//OPTION 2 print path
        else if(userInput == "2"){
            run->printNetwork();
        }
//OPTION 3 send a message
        else if(userInput == "3"){
            run->transmitMsg("messageIn.txt");
        }
//OPTION 4 add a city
        else if(userInput == "4"){
            //Choose new city and previous city
            string newCity;
            string prevCity;
            cout<<"Enter a city name: "<<endl;
            getline(cin,newCity);
            cout<<"Enter a previous city name: "<<endl;
            getline(cin,prevCity);

            run->addCity(newCity,prevCity);
        }
        else if (userInput == "5"){
            cout<<"Enter a city name: "<<endl;
            getline(cin,userInput);
            run->deleteCity(userInput);
        }
        else if (userInput == "6"){
            run->deleteNetwork();
        }
    }
    cout<<"Goodbye!"<<endl;
    delete run;
    /*if(head->next != NULL){
        run.deleteNetwork();
    }*/

    return 0;
}
