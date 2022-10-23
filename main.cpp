#include <iostream>
#include <string>
#include <vector>
#include <array>
#include "Prefix.h"
using namespace std;

void print(vector<string> input){
    int size=input.size();
    for (int i=0; i<size; i++){
        cout<<"Vector at "<<i<<" :"<<input.at(i)<<endl;
    }
}

int main (){  
    vector<string> list;
    string input;
    //input="* - 5 6 -7"; //variable to hold input as string
    //input="* 5"; //variable to hold input as string
    //input="* - 5 6 7"; //variable to hold input as string
    //input= "2 : 2";
    //input="/ 2 0 :";
    string target=" "; //variable holding the target to aim for the space to differentiate between different ints
    string hold=""; //variable and temp hold space
    string funcinput;
    int targetfound;
    getline (cin >> ws,input); //taking input including spaces
    string input2=input;
    int sizeofin=input.size();
    for (int z=0; z<sizeofin;z++){ //taking input line and putting integers in vector
        targetfound=input2.find(target); // finding location of first space
        if (targetfound==-1){
            hold=input2.substr(0,input2.size());
            list.push_back(hold);
            input2.erase(0,input2.size());
            break;
        }
        else if (targetfound!= -1){
            hold=input2.substr(0,targetfound); // taking out first int out of string input
            list.push_back(hold); //converting input number from string to integer and holding in vector values
            input2.erase(0,targetfound+1);
        }
    };

    for (int i=0; i<sizeofin;i++){
        targetfound=input.find(target); // finding location of first space
        if (targetfound==-1){
            break;
        }
        else if (targetfound!= -1){
            input.erase(targetfound,1);
        }
    }
    int firstint=0;
    sizeofin=input.size();
    
    for (int i=0;i<sizeofin;i++){
        if (input.at(i)=='1' || input.at(i)=='2' || input.at(i)=='3' || input.at(i)=='4' || input.at(i)=='5' || input.at(i)=='6' || input.at(i)=='7' || input.at(i)=='8' || input.at(i)=='9' || input.at(i)=='0'){
            firstint=i;
            break;
        }
    }
    //print(list);
    Prefix preficon;
    preficon.prefix(input, list, firstint);
    //cout<<result<<endl;
    return 0;
}