#include "CommunicationNetwork.h"
#include <fstream>
using namespace std;

CommunicationNetwork::CommunicationNetwork()
{
    head = NULL;
    tail = NULL;
}

void CommunicationNetwork::addCity(std::string nCity, std::string pCity)
{
    //If user wants to replace LA
    if(pCity == "First"){
        City *newHead = new City(nCity,head->next,""); //Sets new node pointed at what head is
        delete head; // delete head
        head = newHead; //reinstate head
    }
    else{
        //Insert new city
        City *current = head;
        while(current->cityName != pCity and current->next != NULL){ // Finds previous city
            current = current->next;
        }
        City *returnNode = new City(nCity,current->next, ""); //same as above
        current->next = returnNode;
    }
}

void CommunicationNetwork::buildNetwork()
{
    //Builds network list
    std::string cityList[10] = {"Los Angeles", "Phoenix", "Denver", "Dallas", "St. Louis", "Chicago",
                                "Atlanta", "Washington, D.C.", "New York", "Boston"};
    //Instating head as LA
    head = new City;
    head->cityName = cityList[0];
    head->next = NULL;
    City *current = head;

    //sets values of list
    int i = 1;
    while(i < 10){
        City *tmp = new City;
        tmp->cityName = cityList[i];
        tmp->next = NULL;
        current->next = tmp;
        current = current->next;
        i++;
    }
    City *tail = current;
    current = head;
    cout<<"===CURRENT PATH==="<<endl;
    while(current != NULL){
        cout<<current->cityName<<" -> ";
        current = current->next;
    }
    cout<<"NULL"<<endl;
    cout<<"=================="<<endl;
}

void CommunicationNetwork::transmitMsg(char *file) //this is like a string
{
    //Read in message
    ifstream inFile;
    inFile.open (file);
    string word;
    //Checks if list
    if(head == NULL){
        cout<<"Empty list"<<endl;
        return;
    }
    //Reads message word by word and prints the word received
    while(inFile >> word){
        City *current = head;
        while(current != NULL){
            current->message = word;
            cout<<current->cityName<<" received "<<current->message<<endl;
            current->message = "";
            current = current->next;
        }
    }
}

void CommunicationNetwork::printNetwork()
{
            City *current = head;
            cout<<"===CURRENT PATH==="<<endl;
            while(current != NULL){
                cout<<current->cityName<<" -> ";
                current = current->next;
            }
            cout<<"NULL"<<endl;
            cout<<"=================="<<endl;
}

CommunicationNetwork::~CommunicationNetwork(){}
