/*
Question:
Write a program to find sum of n numbers
*/

#include<iostream>
using namespace std;
int main(){
    int n,sum=0;
    cin>>n;
    while(n>0){
        sum=sum+n;
        n--;
    }
    cout<<sum;
    return 0;
}
