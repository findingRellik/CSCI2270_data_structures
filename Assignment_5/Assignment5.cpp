#include "Queue.h"
#include <iostream>
#include <sstream>

using namespace std;

int main()
{
    Queue *myQueue = new Queue(10);

    string userInput;
    while(userInput != "5"){
        cout<<"======Main Menu====="<<endl;
        cout<<"1. Enqueue word"<<endl;
        cout<<"2. Dequeue word"<<endl;
        cout<<"3. Print queue"<<endl;
        cout<<"4. Enqueue sentence"<<endl;
        cout<<"5. Quit"<<endl;

        getline(cin,userInput);
//OPTION 1 enqueue word
        if(userInput == "1"){
            cout<<"word: ";
            getline(cin,userInput);
            myQueue->enqueue(userInput);
        }
//OPTION 2 dequeue word
        else if(userInput == "2"){
            myQueue->dequeue();
        }
//OPTION 3 print queue
        else if(userInput == "3"){
            myQueue->printQueue();
        }
//OPTION 4 enqueue sentence
        else if(userInput == "4"){
            cout<<"sentence: ";
            getline(cin,userInput);
            string word;
            istringstream stream(userInput);
            while(stream >> word){
                myQueue->enqueue(word);
            }
        }

    }
    cout<<"Goodbye!"<<endl;
    delete myQueue;
}
