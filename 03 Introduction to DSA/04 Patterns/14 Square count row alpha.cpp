/*
Question:
Write a program to print following pattern:
             ABC
             BCD
             CDE
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
        while(j<n){
            char ch = alpha+i+j;
            cout<<ch<<" ";
            j++;
        }
        cout<<endl;
        i++;
    }
    return 0;
}