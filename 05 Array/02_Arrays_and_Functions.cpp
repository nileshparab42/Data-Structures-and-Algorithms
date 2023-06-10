// Arrays uses pass by reference behavior with functions

void setinit(int arr[],int size,int value){
    for(int i=0;i<size;i++){
        arr[i]=value;
    }
}

#include<iostream>
#include<string.h>
using namespace std;
int main(){
    int arr[2]={1,2};
    for(auto i:arr){
        cout<<i<<endl;
    }
    int size=2;
    setinit(arr,size,200);
    for(auto i:arr){
        cout<<i<<endl;
    }
}