//Assignment 3, Austin Metzner, Yang
#include <iostream>
#include <fstream>

using namespace std;

struct Node{
    int value;
    string city;
    string message;
    Node *next = NULL;
};


int main()
{
    cout<<"======Main Menu======"<<endl;
    cout<<"1. Build	Network"<<endl;
    cout<<"2. Print	Network	Path"<<endl;
    cout<<"3. Transmit Message Coast-To-Coast"<<endl;
    cout<<"4. Add City"<<endl;
    cout<<"5. Quit"<<endl;

    ifstream inFile;
    inFile.open ("messageIn.txt");

    int userInput;
    while(userInput != 5){

        cout<<"Please choose an option above (1-5): ";
        cin>>userInput;

        string cityList[10] = {"Los Angeles", "Phoenix", "Denver", "Dallas", "St. Louis", "Chicago", "Atlanta", "Washington, D.C.", "New York", "Boston"};

        Node *head = new Node;
        head->city = cityList[0];
        head->next = NULL;
        Node *current = head;

        int i = 1;
        while(i < 10){
            Node *tmp = new Node;
            tmp->city = cityList[i];
            tmp->next = NULL;
            current->next = tmp;
            current = current->next;
            i++;
        }
        Node *tail = current;
//OPTION 1
        if(userInput == 1){
            current = head;
            cout<<"===CURRENT PATH==="<<endl;
            while(current != NULL){
                cout<<current->city<<" -> ";
                current = current->next;
            }
            cout<<"NULL"<<endl;
            cout<<"=================="<<endl;
        }
//OPTION 2
        else if(userInput == 2){
            current = head;
            cout<<"===CURRENT PATH==="<<endl;
            while(current != NULL){
                cout<<current->city<<" -> ";
                current = current->next;
            }
            cout<<"NULL"<<endl;
            cout<<"=================="<<endl;
        }
//OPTION 3
        else if(userInput == 3){

            string word;
            while(inFile >> word){
                current = head;
                while(current != NULL){
                    current->message = word;
                    cout<<current->city<<" received "<<current->message<<endl;
                    current->message = "";
                    current = current->next;
                }
            }
        }
//OPTION 4
        else if(userInput == 3){
            string word;
            while(inFile >> word){
                current = head;
                while(current != NULL){
                    current->message = word;
                    cout<<current->city<<" received "<<current->message<<endl;
                    current->message = "";
                    current = current->next;
                }
            }
        }
        else if(userInput == 4){
            string newCity;
            cout<<"Enter a city name: "<<endl;
            cin>>newCity;
            string prevCity;
            cout<<"Enter a previous city name: "<<endl;
            cin>>prevCity;
            if(prevCity == "First"||"first"){
                current = head;
                current->next = head;
                current->city = newCity;
            }
            else{
                bool found = false;
                Node *returnNode = new Node;
                current = head;
                while(!found and current !=NULL){
                    if(current->city==prevCity){
                        found = true;
                        returnNode = current;
                    }
                    else{
                        current = current->next;
                    }
                }
                current->city = newCity;
                current->next = returnNode->next;
                returnNode->next = current;
            }
        }

        else{cout<<"Not a valid input"<<endl;}

    }
    cout<<"Goodbye!"<<endl;

    return 0;
}
