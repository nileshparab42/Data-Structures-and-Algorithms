/*
Question:
Write a program to print following pattern:
             ABC
             DEF
             GHI
*/
#include <iostream>
using namespace std;
int main() {
    int n,i,j;
    char alpha = 'A';
    cin>>n;
    i=0;
    while(i<n){
        j=0;
        while(j<n){
            char ch = alpha;
            cout<<alpha<<" ";
            alpha=alpha+1;
            j++;
        }
        cout<<endl;
        i++;
    }
    return 0;
}