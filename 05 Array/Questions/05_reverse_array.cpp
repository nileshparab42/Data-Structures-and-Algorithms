#include<iostream>
#include<string.h>
using namespace std;

void reverseArray(int arr[],int size){
    int start=0, end=size-1;
    while(start<end){
        swap(arr[start],arr[end]);
        start++;
        end--;
    }
}

int main(){
    int arr[7]={10,20,30,40,50,60,70};
    reverseArray(arr,7);
    for(auto i:arr){
        cout<<i<<" ";
    }
}