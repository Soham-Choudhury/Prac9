#include "Prefix.h"
#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;
string Prefix::prefix(string input, vector<string> list, int firstint){
    stack<string> prefix;
    bool test=0;
    int size = input.size();
    int sizelist = list.size();
    //int result=0;
    int oper1=0;
    int oper2=0;
    string hold;
    int hold2;
    string output;
    if (sizelist-(firstint+1)!=firstint){ //checking if operators and operands are the right ratio
        output="Error";
        cout<<output<<endl;
        return output;
    }
    if (firstint==0){ //checking if first integer is at 0
        output="Error";
        cout<<output<<endl;
        return output;
    }
    for (int i=0;i<size;i++){
        if (input.at(i)!='1' && input.at(i)!='2' && input.at(i)!='3' && input.at(i)!='4' && input.at(i)!='5' && input.at(i)!='6' && input.at(i)!='7' && input.at(i)!='8' && input.at(i)!='9' && input.at(i)!='0' && input.at(i)!='+' && input.at(i)!='*' && input.at(i)!='-' && input.at(i)!='/'){
            output="Error";
            cout<<output<<endl;
            return output;
        }
    }
    for (int i=firstint; i<sizelist;i++){
        hold=list.at(i);
        if (hold=="+" || hold=="*" || hold=="-" || hold=="/"){ //checking if any operands after first integer
            output="Error";
            cout<<output<<endl;
            return output;
        }
        hold2=stoi(hold);
        if (hold2<0 || hold2>99){ //checking if operands are within 0 and 99
            output="Error";
            cout<<output<<endl;
            return output;
        }
    }
    for (int i=size-1; i>= 0; i--) {
        //test input is "* - 5 6 7";
        for (int z=0;z<size;z++){
            //cout<<firstint<<endl;
            if (firstint-z-1<0){
                break;
            }
            if (z==0){
                hold=list.at(firstint);
                oper1=stoi(hold);
            }
            hold=list.at(firstint+z+1);
            oper2=stoi(hold);
            if (list.at(firstint-z-1)=="+"){
                //cout<<"using +"<<endl;
                oper1=oper1 + oper2;
            }
            else if(list.at(firstint-z-1)=="-"){
                //cout<<"using -"<<endl;
                oper1=oper1 - oper2;
                //cout<<"oper1 is "<<oper1<<endl;

            }
            else if(list.at(firstint-z-1)=="*"){
                //cout<<"using *"<<endl;
                oper1=oper1 * oper2;
            }
            else if(list.at(firstint-z-1)=="/"){
                //cout<<"using /"<<endl;
                if (oper2==0){
                    output="Error";
                    cout<<output<<endl;
                    return output;
                }
                oper1=oper1 / oper2;
            }
        }
        //cout<<"left math"<<endl;
        if (input.at(i)=='+' || input.at(i)=='*' || input.at(i)=='-' || input.at(i)=='/') {
            //test input is "* - 5 6 7";
            string operator1 = prefix.top();
            string hold=prefix.top();
            if (test==1){
                cout<<"Operator 1 is: "<<hold<<endl;
            }
            prefix.pop();
            string operator2 = prefix.top();
            hold=prefix.top();
            if (test==1){
                cout<<"Operator 2 is: "<<hold<<endl;
            }
            prefix.pop();
            string temp;
            if (i==0){
                temp = ""+operator1+input.at(i)+operator2+"";
            }
            else {
                temp = "("+operator1+input.at(i)+operator2+")";
            }
            prefix.push(temp);
            } 
        else {
            prefix.push(string(1, input.at(i)));
        }
    }
    //cout<<"problem"<<endl;
    output=prefix.top();
    string output2;
    string target=" ";
    int sizeofout=output.size();
    for (int i=0; i<sizeofout;i++){
        cout<<output.at(i)<<" ";
    }
    cout<<" = "<<oper1<<endl;
    return output2;
}
