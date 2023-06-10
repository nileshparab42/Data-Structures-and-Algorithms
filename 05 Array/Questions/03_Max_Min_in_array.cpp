#include<iostream>
#include<string.h>
#include<limits.h>
using namespace std;

void maxAndMin(int arr[],int size){
    int mini=INT_MAX,maxi=INT_MIN;
    for(int i=0;i<size;i++){
        if(arr[i]<mini){
            mini=arr[i];
        }
        if(arr[i]>maxi){
            maxi=arr[i];
        }
            
    }
    cout<<"Maximum element is "<<maxi<<endl;
    cout<<"Minimum element is "<<mini<<endl;
}

int main(){
    int arr[7]={10,20,30,40,50,60,70};
    maxAndMin(arr,7);
}