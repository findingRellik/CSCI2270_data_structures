#include "MovieTree.h"
#include <iostream>

using namespace std;

MovieTree::MovieTree(){ root = NULL;}
MovieTree::~MovieTree(){
    DeleteAll();
}

void MovieTree::DeleteAll()
{
    DeleteAll(root);
}
//Recursive function to print tree
void MovieTree::DeleteAll(MovieNode * node){
    if( node == NULL )
        return;
    if( node->leftChild != NULL )
        DeleteAll( node->leftChild );
    if( node->rightChild != NULL )
        DeleteAll( node->rightChild );
    cout<<"Deleting: "<<node->title<<endl;
    delete node;
    return;
    /**MovieNode *tmp = new MovieNode;
    if(node->rightChild!=NULL)
        DeleteAll(node->rightChild);
    cout<<"Deleting: "<<node->title<<endl;
    if(node->leftChild!=NULL)
        DeleteAll(node->leftChild);*/
}


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
        } else if(foundMovie->title<title){
            foundMovie = foundMovie->rightChild;
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
        if(foundMovie->quantity <= 0){
            MovieNode *min = new MovieNode;
            if(foundMovie == NULL){
                cout<<"Movie not found."<<endl;
            }
            else{
                //Root case
                if(foundMovie->parent==NULL){
                    min = foundMovie->rightChild;
                    if(min->leftChild == NULL){
                        min->leftChild = foundMovie->leftChild;
                        min->parent = foundMovie->parent;
                    }
                    while(min->leftChild != NULL){
                        min = min->leftChild;
                    }
                    min->parent->leftChild = min->rightChild;
                    min->parent = NULL;
                    min->leftChild = foundMovie->leftChild;
                    min->rightChild = foundMovie->rightChild;
                    foundMovie->rightChild->parent = min;
                    foundMovie->leftChild->parent = min;
                    root = min;
                    delete foundMovie;
                    return;
                }
                // 2 Children case
                else if(foundMovie->leftChild != NULL && foundMovie->rightChild != NULL){
                    min = foundMovie->rightChild;
                    while(min->leftChild != NULL){
                        min = min->leftChild;
                    }
                   if(min->parent != foundMovie){
                        min->parent->leftChild = min->rightChild;//Transfers left branch to parent
                        min->parent = foundMovie->parent;
                    } else{
                        //cout<<"IN ELSE"<<endl;
                        //min->parent->leftChild = min->rightChild;
                        min->parent = foundMovie->parent;
                        foundMovie->leftChild->parent = min;
                        min->leftChild = foundMovie->leftChild;
                        if(foundMovie->parent->leftChild == foundMovie)
                            foundMovie->parent->leftChild = min;
                        if(foundMovie->parent->rightChild == foundMovie)
                            foundMovie->parent->rightChild = min;
                        delete foundMovie;
                        return;

                    }
                    if(foundMovie->parent->leftChild == foundMovie)
                        foundMovie->parent->leftChild = min;
                    if(foundMovie->parent->rightChild == foundMovie)
                        foundMovie->parent->rightChild = min;;
                    min->leftChild = foundMovie->leftChild;
                    min->rightChild = foundMovie->rightChild;
                    foundMovie->rightChild->parent = min;
                    foundMovie->leftChild->parent = min;
                    delete foundMovie;
                    return;
                }
                // 1 child cases
                else if(foundMovie->leftChild != NULL && foundMovie->rightChild == NULL){
                    min = foundMovie->leftChild;
                    min->parent = foundMovie->parent;
                    if(foundMovie->parent->leftChild == foundMovie)
                        foundMovie->parent->leftChild = min;
                    if(foundMovie->parent->rightChild == foundMovie)
                        foundMovie->parent->rightChild = min;;
                    delete foundMovie;
                    return;
                }
                else if(foundMovie->leftChild == NULL && foundMovie->rightChild != NULL){
                    min = foundMovie->rightChild;
                    min->parent = foundMovie->parent;
                    if(foundMovie->parent->leftChild == foundMovie)
                        foundMovie->parent->leftChild = min;
                    if(foundMovie->parent->rightChild == foundMovie)
                        foundMovie->parent->rightChild = min;;
                    delete foundMovie;
                    return;
                }
                //No children case
                else if(foundMovie->leftChild == NULL && foundMovie->rightChild == NULL){
                    if(foundMovie->parent->leftChild == foundMovie)
                        foundMovie->parent->leftChild = NULL;
                    if(foundMovie->parent->rightChild == foundMovie)
                        foundMovie->parent->rightChild = NULL;
                    delete foundMovie;
                    return;
                }
                else {cout<<"ERROR"<<endl;}
            }
        //?????????????????????????????????????????
        }
    } else {cout<<"ERROR"<<endl;}
}

int MovieTree::countMovieNodes()
{
    int *counter = new int;
    *counter = 0;
    countMovieNodes(root, counter);
    return *counter;
}

void MovieTree::countMovieNodes(MovieNode *node, int *c)
{
    if(node->leftChild!=NULL)
        countMovieNodes(node->leftChild, c);
    *c+=1;
    if(node->rightChild!=NULL)
        countMovieNodes(node->rightChild, c);
}

void MovieTree::deleteMovieNode(std::string title)
{
    MovieNode *foundMovie = root;
    MovieNode *min = new MovieNode;
    while(foundMovie != NULL){
        if(foundMovie->title>title){
            foundMovie = foundMovie->leftChild;
        } else if(foundMovie->title<title){
            foundMovie = foundMovie->rightChild;
        } else{
            break; //Exit loop once titles match
        }
    }
    if(foundMovie == NULL){
        cout<<"Movie not found."<<endl;
    }
    else{
        //Root case
        if(foundMovie->parent==NULL){
            min = foundMovie->rightChild;
            if(min->leftChild == NULL){
                min->leftChild = foundMovie->leftChild;
                min->parent = foundMovie->parent;
            }
            while(min->leftChild != NULL){
                min = min->leftChild;
            }
            min->parent->leftChild = min->rightChild;
            min->parent = NULL;
            min->leftChild = foundMovie->leftChild;
            min->rightChild = foundMovie->rightChild;
            foundMovie->rightChild->parent = min;
            foundMovie->leftChild->parent = min;
            root = min;
            delete foundMovie;
            return;
        }
        // 2 Children case
        else if(foundMovie->leftChild != NULL && foundMovie->rightChild != NULL){
            min = foundMovie->rightChild;
            while(min->leftChild != NULL){
                min = min->leftChild;
            }
            /**min->parent->leftChild = min->rightChild;//Transfers left branch to parent
            min->parent = foundMovie->parent;*/
           if(min->parent != foundMovie){
                min->parent->leftChild = min->rightChild;//Transfers left branch to parent
                min->parent = foundMovie->parent;
            } else{
                //cout<<"IN ELSE"<<endl;
                //min->parent->leftChild = min->rightChild;
                min->parent = foundMovie->parent;
                foundMovie->leftChild->parent = min;
                min->leftChild = foundMovie->leftChild;
                if(foundMovie->parent->leftChild == foundMovie)
                    foundMovie->parent->leftChild = min;
                if(foundMovie->parent->rightChild == foundMovie)
                    foundMovie->parent->rightChild = min;
                delete foundMovie;
                return;

            }
            /**if(min->rightChild != NULL){
                min->parent->leftChild = min->rightChild;//Transfers left branch to parent
                min->parent = foundMovie->parent;
            }
            else{
                MovieNode *tmp = new MovieNode;
                tmp = min;
                min->parent = foundMovie->parent;
                tmp->parent->leftChild = NULL;
                //tmp = NULL;
                delete tmp;
            }*/
            if(foundMovie->parent->leftChild == foundMovie)
                foundMovie->parent->leftChild = min;
            if(foundMovie->parent->rightChild == foundMovie)
                foundMovie->parent->rightChild = min;;
            min->leftChild = foundMovie->leftChild;
            min->rightChild = foundMovie->rightChild;
            foundMovie->rightChild->parent = min;
            foundMovie->leftChild->parent = min;
            delete foundMovie;
            return;
        }
        // 1 child cases
        else if(foundMovie->leftChild != NULL && foundMovie->rightChild == NULL){
            min = foundMovie->leftChild;
            min->parent = foundMovie->parent;
            if(foundMovie->parent->leftChild == foundMovie)
                foundMovie->parent->leftChild = min;
            if(foundMovie->parent->rightChild == foundMovie)
                foundMovie->parent->rightChild = min;;
            delete foundMovie;
            return;
        }
        else if(foundMovie->leftChild == NULL && foundMovie->rightChild != NULL){
            min = foundMovie->rightChild;
            min->parent = foundMovie->parent;
            if(foundMovie->parent->leftChild == foundMovie)
                foundMovie->parent->leftChild = min;
            if(foundMovie->parent->rightChild == foundMovie)
                foundMovie->parent->rightChild = min;;
            delete foundMovie;
            return;
        }
        //No children case
        else if(foundMovie->leftChild == NULL && foundMovie->rightChild == NULL){
            if(foundMovie->parent->leftChild == foundMovie)
                foundMovie->parent->leftChild = NULL;
            if(foundMovie->parent->rightChild == foundMovie)
                foundMovie->parent->rightChild = NULL;
            delete foundMovie;
            return;
        }
        else {cout<<"ERROR"<<endl;}
    }
}
