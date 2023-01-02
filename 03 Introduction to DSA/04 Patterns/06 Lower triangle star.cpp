/*
Question:
Write a program to print following pattern:
             *
             **
             ***
*/
#include <iostream>
using namespace std;
int main() {
    int n,i,j,count=1;
    char alpha = 'A';
    cin>>n;
    i=0;
    while(i<n){
        j=0;
        while(j<=i){
            cout<<"*"<<" ";
            j++;
        }
        cout<<endl;
        i++;
    }
    return 0;
}