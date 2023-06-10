#include<iostream>
#include<vector>
using namespace std;
int BinarySearch(vector<int> arr,int key){
    int s=0;
    int e=arr.size()-1;
    int mid = s+(e-s)/2;
    
    while (s <= e)
    {
        if(arr[mid]==key){
            return mid;
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
    return -1;
}

int main(){
    vector<int> arr{11,23,43,56,72,82,93};
    int key=56;
    cout<<"Element is at: "<<BinarySearch(arr,key);
    return 0;
}