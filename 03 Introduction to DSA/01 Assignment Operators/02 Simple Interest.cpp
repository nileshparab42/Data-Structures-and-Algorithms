/*
Question:
Write a program to calculate Simple interest
*/

#include<iostream>
using namespace std;
int main(){
    int p,r,t;
    float si;
    cin>>p>>r>>t;
    si=(p*r*t)/100;
    cout<<si;
    return 0;
}
