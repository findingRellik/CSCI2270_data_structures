#include "HashTable.h"
#include <iostream>

using namespace std;

int main(/*int argc, char *argv[]*/)
{
    HashTable *m = new HashTable;//Instance of hashtable
    m->initialize();
    string userInput;
    while(userInput != "5")
    {
        cout << "======Main Menu======" << endl;
        cout << "1. Insert movie" << endl;
        cout << "2. Delete movie" << endl;
        cout << "3. Find movie" << endl;
        cout << "4. Print table contents" << endl;
        cout << "5. Quit" << endl;
        getline(cin,userInput);
//OPTION 1 insert movie
        if(userInput == "1")
        {
            int movie;
            cout << "Enter title:" << endl;
            getline(cin,userInput);
            cout << "Enter year:" << endl;
            cin>>movie;
            cin.ignore();
            m->insertMovie(userInput,movie);
        }
//OPTION 2 delete movie
        else if(userInput == "2")
        {
            cout << "Enter title:" << endl;
            getline(cin,userInput);
            m->deleteMovie(userInput);
        }
//OPTION 3 find movie
        else if(userInput == "3")
        {
            cout << "Enter title:" << endl;
            getline(cin, userInput);
            m->findMovie(userInput);
        }
//OPTION 4 print
        else if (userInput == "4")
        {
            m->printTableContents();
        }
    }
    cout<<"Goodbye!"<<endl;
    delete m;

    return 0;
}
