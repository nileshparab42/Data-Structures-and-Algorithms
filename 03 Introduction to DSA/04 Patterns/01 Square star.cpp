/*
Question:
Write a program to print following pattern:
             321
             321
             321
*/
#include <iostream>
using namespace std;
int main() {
    int n,i,j;
    cin>>n;
    i=0;
    while(i<n){
        j=0;
        while(j<n){
            cout<<n-j;
            j++;
        }
        cout<<endl;
        i++;
    }
    
    return 0;
}