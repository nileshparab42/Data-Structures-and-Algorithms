#include<iostream>
#include<vector>
using namespace std;
int linearSearch(vector<int> arr,int key){
    for(int i=0;i<arr.size();i++){
        if(arr[i]==key){
            return i;
        }
    }
    return -1;
}

int main(){
    vector<int> arr{6,7,4,3,2,1};
    int key=11;
    cout<<"Element is at: "<<linearSearch(arr,key);
    return 0;
}