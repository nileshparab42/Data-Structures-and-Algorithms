/*
Question:
Write a program to print following pattern:
             123
             456
             789
*/
#include <iostream>
using namespace std;
int main() {
    int n,i,j,count=1;
    cin>>n;
    i=0;
    while(i<n){
        j=0;
        while(j<n){
            cout<<count<<" ";
            count++;
            j++;
        }
        cout<<endl;
        i++;
    }
    
    return 0;
}