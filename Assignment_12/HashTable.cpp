#include <iostream>
#include "HashTable.h"
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

HashTable::HashTable(){}

HashTable::~HashTable(){}

void HashTable::initialize()
{

    for(int i = 0; i < 10; i++)
    {
        HashElem* nullNode = new HashElem("", 0);
        hashTable[i] = nullNode;
    }
}

void HashTable::printTableContents()
{
    bool empty = true;
    for(int i = 0; i < 10 ; i++)
    {
        if(hashTable[i]->next != NULL)
        {
            HashElem* tmp = hashTable[i]->next;
            while(tmp != NULL)
            {
                cout<<tmp->title<<":"<<tmp->year<<endl;
                tmp = tmp->next;
            }
            empty = false;
        }

    }
    if(empty == true)
        cout << "empty" << endl;
}

void HashTable::insertMovie(std::string name, int year)
{
    HashElem* mov = new HashElem(name,year);

    int index = hashSum(name, 10);
    //cout<<index<<endl;

    if(hashTable[index]->next == NULL)
    {
        mov->previous = hashTable[index];
        hashTable[index]->next = mov;
    }
    else
    {
        HashElem* tmp = hashTable[index]->next;
        while(tmp->next != NULL)
        {
            if(tmp->title == name)
            {
                return;
            }
            tmp = tmp->next;
        }
        tmp->next = mov;
        mov->previous = tmp;
        mov->next = NULL;
    }
}

void HashTable::deleteMovie(std::string name)
{
    int index = hashSum(name, 10);
    if(hashTable[index]->next != NULL)
    {
        HashElem* tmp = hashTable[index]->next;
        while(tmp != NULL)
        {
            if(tmp->title == name)
            {
                tmp->previous->next = tmp->next;
                if(tmp->next != NULL)
                {
                    tmp->next->previous = tmp->previous;
                }
                delete tmp;
                return;
            }
            tmp = tmp->next;
        }
        cout << "not found" << endl;
    }
    else
        cout << "not found" << endl;
}

void HashTable::findMovie(std::string name)
{
    int index = hashSum(name, 10);
    if(hashTable[index]->next != NULL)
    {
        HashElem* tmp = hashTable[index]->next;
        while(tmp != NULL)
        {
            if(tmp->title == name)
            {
                cout << index << ":" <<tmp->title<< ":" <<tmp->year<< endl;
                return;
            }
            else
                tmp = tmp->next;
        }
        cout << "not found" << endl;
    }
    else
        cout << "not found" << endl;
}

int HashTable::hashSum(std::string x, int s)
{
    int sum = 0;
    for(int i = 0; i < x.length(); i++)
        sum += x[i];
    sum = sum % s;
    return sum;
}

