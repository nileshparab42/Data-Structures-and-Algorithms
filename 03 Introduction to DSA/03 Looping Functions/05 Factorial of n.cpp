/*
Question:
Write a program to find factorial of n numbers
*/

#include<iostream>
using namespace std;
int main(){
    int n,fact=1;
    cin>>n;
    while(n>1){
        fact=fact*n;
        n--;
    }
    cout<<fact;
    return 0;
}
