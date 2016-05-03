//Assignment 3, Austin Metzner, Yang
#include <iostream>
#include <fstream>

using namespace std;

struct Node{
    int key;
    Node *next;
    Node *previous;
};

int main()
{
    int a[5] = {1,2,3,4,5};

    Node *head = new Node;
    head->previous = NULL;
    head->next= NULL;
    head->key = a[0];
    Node *tmp = head;
    int i = 1;
    while(i < 5){
        Node *current = new Node;
        current->previous = tmp;
        current->next = NULL;
        current->key = a[i];
        tmp->next=current;
        tmp = current;
        i++;
    }
    tmp = head;
    while(tmp != NULL){
        cout<<tmp->key<<endl;
        tmp = tmp->next;
    }
    tmp = tail;
    while(tmp != NULL){
        cout<<tmp->key<<endl;
        tmp = tmp->previous;
    }
    //inserting node head middle tail
    Node *left = head;
    Node *n = new Node;
    n->key =99;
    n->next = left->next;
    left->next->previous = n;

    //Node *l = left->next;
    //l->previous = n

    left-> = n;
    n->previous = left;

    tmp = head;
    while(tmp != NULL){
        cout<<tmp->key<<endl;
        tmp = tmp->next;
    }
    //deleting node
    Node *node = tmp;
    node->previous->next = node->next;
    node->next->previous = node->previous;
    delete node;

    //deleting a head node;
    tmp = head;
    head = head->next;
    head->previous = NULL;
    delete tmp;

    //Delete tail
    tmp = tail;
    tail = tail->previous;
    tail->next = NULL;
    delete tmp;

    return 0;
}
