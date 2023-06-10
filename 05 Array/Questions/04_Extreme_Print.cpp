#include<iostream>
#include<string.h>
using namespace std;

void extremePrint(int arr[],int size){
    int start=0, end=size-1;
    while(start<=end){
        if(start==end){
            cout<<arr[start]<<" ";
            start++;
            end--;
        }
        else{
            cout<<arr[start]<<" ";
            cout<<arr[end]<<" ";
            start++;
            end--;
        }
            
    }
}

int main(){
    int arr[7]={10,20,30,40,50,60,70};
    extremePrint(arr,7);
}