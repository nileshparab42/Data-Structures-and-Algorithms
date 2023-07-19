#include<iostream>
#include<limits.h>
using namespace std;

void merge(int* arr,int s,int e){
    int mid=s+(e-s)/2;

    int len1=mid-s+1;
    int len2=e-mid;

    int* a1=new int(len1);
    int* a2=new int(len2);

    int k=s;
    for(int i=0;i<len1;i++){
        a1[i]=arr[k];
        k++;
    }
    k=mid+1;
    for(int i=0;i<len2;i++){
        a2[i]=arr[k];
        k++;
    }
    
    int a1p=0;
    int a2p=0;
    int mainpointer=s;

    while(a1p<len1 && a2p<len2){
        if(a1[a1p]<a2[a2p]){
            arr[mainpointer]=a1[a1p];
            a1p++;
        }
        else{
            arr[mainpointer]=a2[a2p];
            a2p++;
        }
        mainpointer++;
    }
    while(a1p<len1){
        arr[mainpointer]=a1[a1p];
        a1p++;
        mainpointer++;
    }
    while(a2p<len2){
        arr[mainpointer]=a2[a2p];
        a2p++;
        mainpointer++;
    }
}

void mergeSort(int* arr,int s,int e){
    if(s>=e){
        return;
    }
    int mid=s+(e-s)/2;
    mergeSort(arr,s,mid);
    mergeSort(arr,mid+1,e);
    merge(arr,s,e);
}

int main(){
    int arr[]={38,27,43,3,9,20};
    int s=0;
    int e=5;
    mergeSort(arr,s,e);
    for(auto i:arr){
        cout<<i<<" ";
    }
}