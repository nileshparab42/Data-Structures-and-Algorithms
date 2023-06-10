#include<iostream>
#include<string.h>
using namespace std;

void extremePrint(int arr[],int size){
    int start=0, end=size-1;
    while(start<end){
        if(arr[start]==0)
            start++;
        else if(arr[end]==1)
            end--;
        else 
            swap(arr[start],arr[end]);
    }
}

int main(){
    int arr[7]={0,1,1,0,0,1,0};
    extremePrint(arr,7);
    for(auto i:arr){
        cout<<i;
    }
}