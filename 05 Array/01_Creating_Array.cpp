#include<iostream>
#include<string.h>
using namespace std;
int main(){
    int arr[10]={1,2,3,4,5};  //rest all elements will be zero
    int brr[]={1,2,3,4,5};   //size will be fixed 
    int crr[5]={0};   //sets all elements to zero
    
    //Memset Function
    int drr[10]={1,2,3,4,5};
    memset(drr, 10, 10*sizeof(arr[0]));

    //Bad practice 
    int n;
    cin>>n;
    int err[n]={0};

    // Character array
    char ch[10]={'H','E','L','L','O'};  // rest will be empty

    // Boolean array
    bool bl[10]={0,1,1}; // rest will be 0

    // Float array
    float fl[10]={1.6,4.2,9.5};  //rest will be 0

    //Printing array
    for(auto i:fl){
        cout<<i<<endl;
    }
}