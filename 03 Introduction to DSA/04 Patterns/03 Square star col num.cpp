/*
Question:
Write a program to print following pattern:
             123
             123
             123
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
            cout<<j+1;
            j++;
        }
        cout<<endl;
        i++;
    }
    return 0;
}