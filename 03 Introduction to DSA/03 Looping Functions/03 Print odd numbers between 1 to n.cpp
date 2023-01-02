/*
Question:
Write a program to odd numbers between 1 to n
*/

#include<iostream>
using namespace std;
int main(){
    int n,num=1;
    cin>>n;
    while(num<=n){
        if(num%2!=0){
            cout<<num<<"\n";
        }
        num++;
    }
    return 0;
}
