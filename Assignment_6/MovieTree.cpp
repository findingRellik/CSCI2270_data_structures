#include "MovieTree.h"
#include <iostream>

using namespace std;

MovieTree::MovieTree(){ root = NULL;}
MovieTree::~MovieTree(){}

void MovieTree::printMovieInventory()
{
    printMovieInventory(root);
}
//Recursive function to print tree
void MovieTree::printMovieInventory(MovieNode * node){
    if(node->leftChild!=NULL)
        printMovieInventory(node->leftChild);
    cout<<"Movie: "<<node->title<<" "<<node->quantity<<endl;
    if(node->rightChild!=NULL)
        printMovieInventory(node->rightChild);
}

void MovieTree::addMovieNode(int ranking, std::string title, int releaseYear, int quantity)
{
    //Initialize node
    MovieNode *node = new MovieNode(ranking, title, releaseYear, quantity);
    MovieNode *parent = NULL;
    node->leftChild = NULL;
    node->rightChild = NULL;
    node->parent = NULL;
    //Checks if tree is empty
    if(isEmpty())
        root = node;
    else{ //Adds new node to tree by finding where it fits in
        MovieNode* current = root;
        // Find the Node's parent
        while(current != NULL)
        {
            parent = current;
            if(node->title < current->title)
                current = current->leftChild;
            else
                current = current->rightChild;
        }

        if(parent == NULL){
            root = node;
        }
        //Attaches node to tree
        else if(node->title < parent->title){
           parent->leftChild = node;
           node->parent = parent;
        }
        else{
           parent->rightChild = node;
           node->parent = parent;
        }
    }
}
//Search movie tree
void MovieTree::findMovie(std::string title)
{
    MovieNode *foundMovie = root;
    while(foundMovie != NULL){
        if(foundMovie->title>title){
            foundMovie = foundMovie->leftChild;
            //cout<<foundMovie->title<<endl;
        } else if(foundMovie->title<title){
            foundMovie = foundMovie->rightChild;
            //cout<<foundMovie->title<<endl;
        } else{
            break; //Exit loop once titles match
        }
    }
    if(foundMovie == NULL){
        cout<<"Movie not found."<<endl;
    } else{
    cout<<"Movie Info:"<< endl;
    cout<<"==========="<< endl;
    cout<<"Ranking:"<<foundMovie->ranking<< endl;
    cout<<"Title:"<<foundMovie->title<< endl;
    cout<<"Year:"<<foundMovie->year<< endl;
    cout<<"Quantity:"<<foundMovie->quantity<<endl;
    }
}
//Search tree and rent movie
void MovieTree::rentMovie(std::string title)
{
    MovieNode *foundMovie = root;
    while(foundMovie != NULL){
        if(foundMovie->title>title){
            foundMovie = foundMovie->leftChild;
            //cout<<foundMovie->title<<endl;
        } else if(foundMovie->title<title){
            foundMovie = foundMovie->rightChild;
            //cout<<foundMovie->title<<endl;
        } else{
            break;
        }
    }
    if(foundMovie == NULL){
        cout<<"Movie not found."<<endl;
    }
    //If movie is in stock
    else if(foundMovie->quantity > 0){
        foundMovie->quantity--;
        cout<<"Movie has been rented."<<endl;
        cout<<"Movie Info:"<<endl;
        cout<<"==========="<<endl;
        cout<<"Ranking:"<<foundMovie->ranking<<endl;
        cout<<"Title:"<<foundMovie->title<<endl;
        cout<<"Year:"<<foundMovie->year<<endl;
        cout<<"Quantity:"<<foundMovie->quantity<<endl;
    }
    //If movie is out of stock
    else
        cout<<"Movie out of stock."<< endl;
}
