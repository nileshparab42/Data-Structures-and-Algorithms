/*
Question:
Write a program to print following pattern:
             1
             23
             345
*/
#include <iostream>
using namespace std;
int main() {
    int n,i,j,count,num=1;
    cin>>n;
    i=0;
    while(i<n){
        j=0;
        while(j<=i){
            count=num+i+j;
            cout<<count<<" ";
            j++;
        }
        cout<<endl;
        i++;
    }
    return 0;
}