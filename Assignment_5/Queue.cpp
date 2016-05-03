#include "Queue.h"
#include <iostream>
#include <sstream>

using namespace std;

Queue::Queue(int qSize){
    queueSize = qSize;
    arrayQueue = new string[qSize];
    queueHead=0;
    queueTail=0;
}
Queue::~Queue(){
    //delete arrayQueue;
}
//circular queue methods
void Queue::enqueue(std::string word){
    if(! queueIsFull()){//cheack if queue is full
        arrayQueue[queueTail]=word; //add word to tail
        queueCount++; // increment items in queue
        if(queueTail==queueSize-1){//sets new tail location after item added
            queueTail = 0;
        } else{
            queueTail++;
        }
        cout<<"E: "<<word<<endl;
        cout<<"H: "<<queueHead<<endl;
        cout<<"T: "<<queueTail<<endl;
    }
    else{cout<<"Queue is full."<<endl;}
}

std::string Queue::dequeue(){ //should send through network, call transmit msg
    string value;
    if(! queueIsEmpty()){//checks if queue is empty
        value = arrayQueue[queueHead];//gets value of head
        queueCount--;//decrement number of items in queue
        if(queueHead == queueSize-1){
            queueHead = 0;
        } else{
            queueHead++;
        }
        cout<<"H: "<<queueHead<<endl;//out put values
        cout<<"T: "<<queueTail<<endl;
        cout<<"word: "<<value<<endl;
    }
    else{cout<<"Queue is empty."<<endl;}
    return value;
}

void Queue::printQueue(){
    if(queueIsEmpty()==true){
        cout<<"Empty"<<endl;
        return;
    }
    if(queueHead < queueTail){//prints from head to tail
        for(int i = queueHead; i < queueTail; i++){
            cout<<i<<": "<<arrayQueue[i]<<endl;
        }
    } else{//prints from head to end, then beginning to tail if head >= tail
        for(int i = queueHead; i < queueSize; i++){
            cout<<i<<": "<<arrayQueue[i]<<endl;
        }
        for(int i = 0; i < queueTail; i++){
            cout<<i<<": "<<arrayQueue[i]<<endl;
        }
    }
}

bool Queue::queueIsFull(){//send when full
    if(queueCount==queueSize){
        return true;
    }
    else {return false;}
}

bool Queue::queueIsEmpty(){ //send when empty
    if(queueCount==0){
        return true;
    }
    else {return false;}
}
   /*
        int queueSize;
        int queueHead;
        int queueTail;
        int queueCount;
        std::string *arrayQueue;*/


