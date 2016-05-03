//Austin Metzner, Assignment 2, Rhonda Hoenigman, Yang

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <math.h>
#include <cstring>
//#include <algorithm>
//#include <functional>

using namespace std;

struct wordData{
 string word = "";
 int wordcount = 0;
};

int* doubleArray(int p[], int length){
    int *newArray = new int[length*2];
    for(int i = 0; i < length; i++){
        newArray[i] = p[i];
    }
    return newArray;
}
wordData *ArrayDynamicAllocation(wordData array[], int size){
    wordData *p = new wordData[size];
    for(int i = 0; i < size; i++){
        p[i] = array[i];
    }
    wordData *p2;
    int newSize = size*2;
    p2 = new wordData[newSize];
    for(int x = 0; x < newSize; x++){
        p2[x] = p[x];
    }
    //newSize = newSize * 2;
    delete []p;
    p = p2;
    return p;// , newSize;
}
//Finds if word is common or not
bool nonCommonWord(string input){
    string commonWords[50] = {"the","be","to","of","and","a","in","that","have","i","it","for","not","on","with","he","as",
    "you","do","at","this","but","his","by","from","they","we","say","her","she","or","an","will","my",
    "one","all","would","there","their","what","so","up", "out","if","about","who","get","which","go","me"};
    bool theResult = true;
    for(int i = 0 ; i < 50 ; i++){
        if(input == commonWords[i]){
            theResult = false;
            break;
        }
    }
    return theResult;
}
//Checks if word is unique
bool isUnique(wordData k[], string input, int place){
    bool theResult = true;
    for(int i = 0 ; i < place ; i++){
        if(input == k[i].word){
            theResult = false;
            break;
        }
    }
    return theResult;
}

int main(int argc, char *argv[])
{
//Open the file and check if it has the file
    ifstream inFile;
    inFile.open(argv[1]);
    if(inFile.fail()){
        cout<<"The file was not successfully opened"<<endl;
    }
//Initializing necessary variables
    int length = 100;
    wordData *theWords = new wordData[length];
    int index = 0;
    int timesDoubled = 0;
    int totalNumWords = 0;
    int totalUniqueWords = 0;
//Now to read the file
    string word;
    while(inFile >> word){
//Checking if array is full, if so then doubling it
        if(index == length){
            //theWords = ArrayDynamicAllocation(theWords, length);
            wordData *newArray = new wordData[length*2];
            for(int i = 0; i < length; i++){
                newArray[i] = theWords[i];
            }
            //newArray = theWords;
            delete []theWords;
           theWords = newArray;
            //theWords = NULL;

            /*for(int i = 0; length < length*2; i++){
                newArray[i].word = "";
                newArray[i].wordcount = 0;
            }*/
            /*wordData *theWords = new wordData[length*2];
            for(int i = 0; i < 2*length; i++){
                theWords[i] = newArray[i];
            }
            //theWords = newArray;
            delete []newArray;
            newArray = NULL;
*/
            /*for(int i = 0; i < (length*2); i++){
                cout<<i<<"  "<<theWords[i].wordcount<<" - "<<theWords[i].word<<endl;
               // cout<<theWords[length*2-1].word<<" length*2-1 "<<endl;
            }*/
            length *= 2;
            timesDoubled++;
        }
//Checking if the word is a common word to be excluded from the count
        if(nonCommonWord(word) == false){
            continue;
        }
        theWords[index].word = word;
        if(isUnique(theWords, word, index) == true){
            theWords[index].wordcount++;
        }

        totalNumWords++;//Total number of words counter
//Check if word is in the array already in the array, if it is update the word count
        for(int i = 0; i < index; i++){
            if(theWords[index].word == theWords[i].word){
                theWords[i].wordcount++; //Updates number of times word is used
                theWords[index] = {}; //clears slot for next word since it was added to value of same word
                index--;
                break;
            }
        }
        index++;
    }
    //Algorithm that sorts the array with the most common down to the least//Organizes array with the most common words at the top
    for(int x = index ; x >= 0 ; x--){
        for(int i = 0 ; i < x; i++){
            if(theWords[x].wordcount > theWords[i].wordcount){
                for(int n = x ; n >= i ; n--){//Shifts the elements in the array down
                    theWords[n+1] = theWords[n];
                }
                theWords[i] = theWords[x+1];//moves current greater item to spot of the item just below it
                theWords[x+1] = {};
                break;
            }

        }
    }
//Outputting the final array
    for(int x = 0 ; x < stoi(argv[2]); x++){
        cout<<theWords[x].wordcount<<" - "<<theWords[x].word<<endl;
    }
    cout<<"#"<<endl;
    cout<<"Array doubled: "<<timesDoubled<<endl;
    cout<<"#"<<endl;
    totalUniqueWords = index;//Should be the number of unique words
    cout<<"Unique non-common words: "<<totalUniqueWords<<endl;
    cout<<"#"<<endl;
    cout<<"Total number of non common words: "<<totalNumWords<<endl;
//Close Files
    inFile.close();

    return 0;
}
///////////////////////////////////////////////////////////////////////////////////////



//Austin Metzner Recitation 2, Yang

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

struct wordData{
 string word;
 int wordcount = 0;
};

int* doubleArray(int p[], int length){
    int *newArray = new int[length*2];
    for(int i = 0; i < length; i++){
        newArray[i] = p[i];
    }
    //the second half of newArray should still be garbage
    return newArray;
}

/*{
    newArray = stackArray;
    stackArray = new int[size*2];
    stackArray = newArray;
    size *= 2;
}*/


int main(int argc, char *argv[])
{
    //Open the file and check if it has the file
    ifstream inFile;
    inFile.open(argv[1]);
    if(inFile.fail()){
        cout<<"The file was not successfully opened"<<endl;
    }
//Now to read the file

    int arraySize = 26971;
    //wordData theWords[arraySize];
    wordData *theWords = new wordData[arraySize];

    wordData swapWord[0];
    int index = 0;
    int counter = 0;
    int timeDoubled = 0;

    string word;
    while(inFile >> word){
        theWords[index].word = word;
        theWords[index].wordcount++;
//Check if word is in the array already in the array, if it is update the word count
        for(int i = 0; i < index; i++){
            if(theWords[index].word == theWords[i].word){
                theWords[i].wordcount++;
                //Organizes array with th most common words at the top
                for(int x = 0 ; x < index ; x++){
                    if(theWords[i].wordcount > theWords[x].wordcount){
                        for(int n = index ; n >= x ; n--){//Shifts the elements in the array down
                                theWords[n+1] = theWords[n];
                            }
                        theWords[x] = theWords[i+1];
                        for(int k = (i+1) ; k <= index ; k++){//Shifts the elements in the array up to close the gap
                                theWords[k] = theWords[k+1];
                            }
                        break;
                    }
                }
                theWords[index] = {};
                index--;
                break;
            }
        }
//Algorithm that sorts the array with the most common down to the least
//Check to see if the Array is full, if so, double the size

        index++;
        //counter++;
    }

    ofstream myfile;
    myfile.open ("testReference.txt");

    for(int x = 0 ; x < index; x++){
        cout<<theWords[x].word<<" - "<<theWords[x].wordcount<<"   ";
        myfile<<x<<": "<<theWords[x].word<<" - "<<theWords[x].wordcount<<"  "<<endl;
    }

    //cout<<counter<<endl;

    myfile.close();
    inFile.close();

    return 0;
}
