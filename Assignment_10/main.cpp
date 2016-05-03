//Austin Metzner, Assignment 10, Yang Li
#include <iostream>
#include "Graph.h"
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <vector>
#include <queue>

using namespace std;

struct data
{
    string city = "";
    int number = -1;
};

bool existsAlready(int a[], int num)
{
    for(int i = 0; i < 25; i++)
    {
        if(a[i] == num)
        {
            return true;
        }
        else if(a[i] <= 0 && a[i] != num)
        {
            a[i] = num;
            return false;
        }
    }
}

int main(int argc, char *argv[])
{
    Graph *network = new Graph;//Instance of graph class

    ifstream inFile;
    inFile.open(argv[1]);
    if(inFile.fail())
    {
        cout<<"The file was not successfully opened"<<endl;
    }

//Build Network
    string read;
    string token;
    struct data matrix[16][16];
//Build Matrix
    int x = 0;//ROWS
    while(getline(inFile, read))
    {//Reads Lines --- ROWS
        istringstream ss(read);
        int y = 0;//COLUMNS
        while(getline(ss, token, ','))
        {//Splits lines by comma --- COLUMNS
            if(y == 0 && x == 0)//if(x == 0 && y == 0)
            {
                y++;
                //continue;
            }
            else if(x == 0)//if(x == 0 && y != 0)
            { //reads in first row cities
                matrix[x][y].city = token;
                network->addVertex(token);
                //cout<<"Adding : "<<matrix[x][y].city<<endl;
                y++;
                //continue;
            }
            else if (y == 0)
            {
                matrix[x][y].city = token;
                y++;
            }
            else
            {
                matrix[x][y].number = atoi(token.c_str());
                y++;
                //continue;
            }

        }
        x++;
    }
//Now build edges
    int exists[25] = {0};
    for(int x = 1; x < 16; x++)
    {
        for(int y = 1; y < 16; y++)
        {
            if(matrix[x][y].number > 0)
            {
                if(existsAlready(exists, matrix[x][y].number) == false)
                {
                    network->addEdge(matrix[x][0].city, matrix[0][y].city, matrix[x][y].number);
                    //cout<<"Adding edge: "<<matrix[x][0].city<<" & "<<matrix[0][y].city<<" weight "<<matrix[x][y].number<<endl;
                }
            }
        }
    }
    inFile.close();

    string userInput;
    while(userInput != "4")
    {
        cout << "======Main Menu======" << endl;
        cout << "1. Print vertices" << endl;
        cout << "2. Find districts" << endl;
        cout << "3. Find shortest path" << endl;
        cout << "4. Quit" << endl;
        getline(cin,userInput);
//OPTION 1 print vertices
        if(userInput == "1")
        {
            network->displayEdges();
        }
//OPTION 2 find districts
        else if(userInput == "2")
        {
            network->assignDistricts();
        }
//OPTION 3 find shortest path
        else if(userInput == "3")
        {
            cout << "Enter a starting city:" << endl;
            getline(cin,userInput);
            cout << "Enter an ending city:" << endl;
            string city2;
            getline(cin, city2);

            network->shortestPath(userInput, city2);
        }
    }
    cout<<"Goodbye!"<<endl;
    delete network;

    return 0;
}
