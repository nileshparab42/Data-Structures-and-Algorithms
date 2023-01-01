/*
Question:
Write a program to find out whether the number is Positive, Negative or Zero
*/

#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    if(n<0){
        cout<<"Number is Negative";
    }
    else if(n>0){
        cout<<"Number is Positive";
    }
    else{
        cout<<"Number is Zero";
    }
    return 0;
}
