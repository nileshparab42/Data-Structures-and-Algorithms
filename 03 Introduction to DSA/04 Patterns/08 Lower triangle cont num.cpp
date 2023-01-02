/*
Question:
Write a program to print following pattern:
             1
             23
             456
*/
#include <iostream>
using namespace std;
int main() {
    int n,i,j,count=1;
    cin>>n;
    i=0;
    while(i<n){
        j=0;
        while(j<=i){
            cout<<count<<" ";
            count++;
            j++;
        }
        cout<<endl;
        i++;
    }
    return 0;
}