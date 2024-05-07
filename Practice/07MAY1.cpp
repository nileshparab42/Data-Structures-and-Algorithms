#include<iostream>
#include<vector>
using namespace std;

int binarysearch(vector<int>& arr,int key){
    int s=0;
    int e=arr.size()-1;
    while(s <= e){
        int mid = (s+e)/2;
        if(arr[mid]==key){
            return mid;
        }
        if(arr[mid]>key){
            e=mid-1;
        }
        if(arr[mid]<key){
            s=mid+1;
        }
    }
    return -1;
}

int binarysearchrec(vector<int>& arr,int& key,int& s, int& e){
    if(s > e){
        return -1;
    }
    int mid = (s+e)/2;
    if(arr[mid]==key){
        return mid;
    }
    if(arr[mid]>key){
        e=mid-1;
    }
    if(arr[mid]<key){
        s=mid+1;
    }
    return binarysearchrec(arr,key,s,e);
}

int main(){
    vector<int> a{2,3,5,7,9};
    int key=2;
    int s=0;
    int e=4;
    cout<<binarysearchrec(a,key,s,e);
    return 0;
    
}