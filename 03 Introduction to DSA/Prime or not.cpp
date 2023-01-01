/*
Question:
Write a program to find factorial of n numbers
*/

#include<iostream>
using namespace std;
int main(){
    int n,num,fact=1;
    cin>>num;
    n=num-1;
    while(n>1){
        if(num%n==0){
            cout<<"Number is not Prime";
            return 0;
        }
        n--;
    }
    cout<<"Number is Prime";
    return 0;
}
