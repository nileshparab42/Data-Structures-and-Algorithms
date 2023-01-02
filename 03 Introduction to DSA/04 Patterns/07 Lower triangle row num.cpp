/*
Question:
Write a program to print following pattern:
             1
             22
             333
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
            cout<<i+1<<" ";
            j++;
        }
        cout<<endl;
        i++;
    }
    return 0;
}