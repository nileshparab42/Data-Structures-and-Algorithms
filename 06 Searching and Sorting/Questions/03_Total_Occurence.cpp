#include<iostream>
#include<vector>
using namespace std;
int FirstOcc(vector<int> arr,int key){
    int s=0;
    int e=arr.size()-1;
    int mid = s+(e-s)/2;
    int pos=-1;
    
    while (s <= e)
    {
        if(arr[mid]==key){
            pos=mid;
            e=mid-1;
        }
        else if (arr[mid]<key)
        {
            s=mid+1;
        }
        else{
            e=mid-1;
        }
        mid = s+(e-s)/2;
    }
    return pos;
}

int LastOcc(vector<int> arr,int key){
    int s=0;
    int e=arr.size()-1;
    int mid = s+(e-s)/2;
    int pos=-1;
    
    while (s <= e)
    {
        if(arr[mid]==key){
            pos=mid;
            s=mid+1;
        }
        else if (arr[mid]<key)
        {
            s=mid+1;
        }
        else{
            e=mid-1;
        }
        mid = s+(e-s)/2;
    }
    return pos;
}

int main(){
    vector<int> arr{1,3,4,6,7,7,9};
    int key=7;
    int fpos = FirstOcc(arr,key);
    int lpos = LastOcc(arr,key);
    cout<<"Total Occurence: "<<lpos-fpos+1;
    return 0;
}