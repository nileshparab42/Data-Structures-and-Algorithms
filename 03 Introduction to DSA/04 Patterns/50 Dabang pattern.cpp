/*
Question:
Write a program to print following pattern:
             1234554321
             1234**4321
             123****321
             12******21
             1********1
*/
#include <iostream>
using namespace std;
int main() {
    int n,i,j,st,z;
    cin>>n;
    i=n;
    while(i>0){
        j=1;
        while(j<=i){
            cout<<j<<" ";
            j++;
            }
        st=1;
        while(st<=(n-i+1)*2){
            cout<<"*"<<" ";
            st=st+1;
            }
        z=i;
        while(z>0){
            cout<<z<<" ";
            z--;
            }
        cout<<endl;
        i--;
    }
    return 0;
}