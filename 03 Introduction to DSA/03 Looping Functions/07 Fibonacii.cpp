/*
Question:
Write a program to print fibonacii series
*/
#include<iostream>
using namespace std;
int main(){
    int n,c;
    cin>>n;
    int a=0,b=1;
    cout<<a<<"\n"<<b<<"\n";
    c=a+b;
    cout<<c<<"\n";
    while(c<n){
        a=b;
        b=c;
        c=a+b;
        cout<<c<<"\n";
    }
    return 0;
}
