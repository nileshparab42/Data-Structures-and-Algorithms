#include<iostream>
#include<vector>
using namespace std;
int FirstOcc(vector<int> arr,int key){
    int s=0;
    int ans=-1;
    int e=arr.size()-1;
    int mid;
    while(s <= e){
        mid=s+((e-s)/2);
        if(arr[mid]==key){
            ans=mid;
            e=mid-1;
        }
        else if(arr[mid]<key){
            s=mid+1;
        }
        else if(arr[mid]>key){
            e=mid-1;
        }
    }
    return ans;
}

int main(){
    vector<int> arr{1,3,9};
    int key=7;
    cout<<"Element is at: "<<FirstOcc(arr,key);
    return 0;
}