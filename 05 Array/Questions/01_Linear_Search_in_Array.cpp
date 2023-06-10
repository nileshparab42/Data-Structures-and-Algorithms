#include<iostream>
#include<string.h>
using namespace std;

bool LinearSearch(int arr[],int size,int key){
    for(int i=0;i<size;i++){
        if(arr[i]==key){
            return true;
        }
    }
    return false;
}

int main(){
    int arr[7]={2,9,6,7,4,12,15};
    int key=4;
    bool res=LinearSearch(arr,7,key);
    if (res==true)
        cout<<key<<" is present";
    else
        cout<<key<<" is not present";
    
}