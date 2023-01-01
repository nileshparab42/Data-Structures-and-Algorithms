/*
Question:
Write a program to even numbers between 1 to n
*/

#include<iostream>
using namespace std;
int main(){
    int n,num=1;
    cin>>n;
    while(num<=n){
        if(num%2==0){
            cout<<num<<"\n";    //we can increment 2 directly
        }
        num++;
    }
    return 0;
}
