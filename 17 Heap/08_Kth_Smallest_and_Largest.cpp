#include<iostream>
#include<queue>
using namespace std;

int kthsmallest(int arr[],int n,int k){
    priority_queue<int> pq;
    for(int i=0;i<k;i++){
        pq.push(arr[i]);
    }
    for(int i=k;i<n;i++){
        if(pq.top() > arr[i]){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    return pq.top();
}

int kthgreatest(int arr[],int n,int k){
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<k;i++){
        pq.push(arr[i]);
    }
    for(int i=k;i<n;i++){
        if(pq.top() < arr[i]){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    return pq.top();
}

int main(){

    int arr[10]={3,6,21,1,2,10,12,56,23,58};
    cout<<kthsmallest(arr,10,4)<<"\n";  //6
    cout<<kthgreatest(arr,10,4);  //21
    return 0;
}