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
            wordData *newArray = new wordData[length*2];
            for(int i = 0; i < length; i++){
                newArray[i] = theWords[i];
            }
            delete []theWords;
           theWords = newArray;
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
                x++;
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
