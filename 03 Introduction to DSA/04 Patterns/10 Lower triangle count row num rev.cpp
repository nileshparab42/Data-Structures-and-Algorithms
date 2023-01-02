/*
Question:
Write a program to print following pattern:
             1
             21
             321
*/
#include <iostream>
using namespace std;
int main() {
    int n,i,j,count,num=1;
    cin>>n;
    i=0;
    while(i<n){
        j=0;
        count=num+i;
        while(j<=i){
            cout<<count<<" ";
            count--;
            j++;
        }
        cout<<endl;
        i++;
    }
    return 0;
}