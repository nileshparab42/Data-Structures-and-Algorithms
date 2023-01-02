/*
Question:
Write a program to print following pattern:
             333
             222
             111
*/
#include <iostream>
using namespace std;
int main() {
    int n,i,j,count=1;
    cin>>n;
    i=0;
    while(i<n){
        j=n;
        while(j>0){
            cout<<j<<" ";
            j--;
        }
        cout<<endl;
        i++;
    }
    return 0;
}