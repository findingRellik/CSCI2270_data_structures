//Austin Metzner - Assignment 1 - Rhonda Hoenigman
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

struct notCraigslist{
        int status;
        string type;
        int value;
};

void notSold(notCraigslist A[], int index){
    int counter = 0;
    for(int z = 0 ; z < index ; z++){
        if(A[z].status == 2 ){
            cout<<A[z].type<< ", for sale, "<<A[z].value<<endl;
            counter++;
        } else if (A[z].status == 1 ){
            cout<<A[z].type<< ", wanted, " <<A[z].value<<endl;
            counter++;
        } else{continue;}
    }
    cout<<counter<<" unsold items"<<endl;
}

int main(int argc, char *argv[])
{
    int arraySIZE = 100;
    notCraigslist itemArray[arraySIZE];

//Open the file and check if it has the file
    ifstream inFile;
    inFile.open(argv[1]);
    if(inFile.fail()){
        cout<<"The file was not successfully opened"<<endl;
    }
//Now to read the file
    int place = 0;//coutner or index
    string descript;
    int itemsSold = 0;
    int loopIterations = 0;

    while(getline(inFile, descript, '\n')){
        loopIterations++;
        //Find and set TYPE
        if(descript.find("chicken") != string::npos){// Looks for word then sets it as word.
            itemArray[place].type = "chicken"; // Would've used stringstream except there's an comma next to word and for sale is 2 words where wanted is 1
        } else if(descript.find("microwave") != string::npos){
            itemArray[place].type = "microwave";
        } else if(descript.find("truck") != string::npos){
            itemArray[place].type = "truck";
        } else if(descript.find("dresser") != string::npos){
            itemArray[place].type = "dresser";
        } else if(descript.find("chicken") != string::npos){
            itemArray[place].type = "chicken";
        } else if(descript.find("bike") != string::npos){
            itemArray[place].type = "bike";
        } else{cout<<"could not find TYPE"<<endl;}

        //Determining and setting status:: for sale = 2 wanted = 1 ---- Then finds value of item using stringstream
        string t, f, s;
        int value;
        if(descript.find("sale") != string::npos){
            itemArray[place].status = 2;
            stringstream ss(descript); //Finds the value of the item
            ss >> t >> f >> s >> value;
            itemArray[place].value = value;
        }
        else if(descript.find("wanted") != string::npos){
            itemArray[place].status = 1;
            stringstream ss(descript);
            ss >> t >> s >> value;
            itemArray[place].value = value;
        }
        else{cout<<"could not find STATUS"<<endl;}

    //Finding Appropriate matches
        for(int x = 0; x < place; x++){
            loopIterations++;
            if(itemArray[place].type == itemArray[x].type){//Checks to see if they are even the same type

                if(itemArray[place].status != itemArray[x].status){// makes sure they are no both for sale etc.
                    if(itemArray[place].status == 2){
                        if(itemArray[place].value <= itemArray[x].value){// checks to tee if the price meets the buyer's/sellers needs
                            cout<<itemArray[place].type<<" "<<itemArray[place].value<<endl;
                            for(int n = x ; n < place ; n++){//Shifts the elements in the array over
                                loopIterations++;
                                itemArray[n] = itemArray[(n+1)];
                            }
                            place -= 1;//since item[place] has been shifted over 1
                            itemArray[place] = {}; //Erase that cell
                            place -= 1;//so we start at the empty cell in the next iteration
                            itemsSold++;
                            break;//exits the large for loop
                        } else{ continue; }
                    } else if(itemArray[place].status == 1){
                        if(itemArray[place].value >= itemArray[x].value){
                            cout<<itemArray[place].type<<" "<<itemArray[x].value<<endl;
                            for(int n = x ; n < place ; n++){
                                loopIterations++;
                                itemArray[n] = itemArray[(n+1)];
                            }
                            place -= 1;
                            itemArray[place] = {};
                            place -= 1;
                            itemsSold++;
                            break;
                            } else{ continue; }
                        } else{ cout<<"ERROR"<<endl;}
                } else{ continue; }

            } else{ continue; }
        }
        place++;
    }
    inFile.close();
cout<<"#"<<endl;
    cout<<"Items Sold: "<<itemsSold<<endl;
    notSold(itemArray, place);
cout<<"#"<<endl;
    cout<<"Loop iterations: "<<loopIterations<<endl;

    return 0;
}

