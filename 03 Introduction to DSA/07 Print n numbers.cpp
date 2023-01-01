/*
Question:
Write a program to print n numbers
*/

#include<iostream>
using namespace std;
int main(){
    int n,num=1;
    cin>>n;
    while(num<=n){
        cout<<num<<"\n";
        num++;
    }
    return 0;
}
