#include<iostream>
#include<limits.h>
using namespace std;
void minMax(int arr[][3],int n){
    int mini=INT_MAX;
    int maxi=INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]<mini){
                mini=arr[i][j];
            } 
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]>maxi){
                maxi=arr[i][j];
            } 
        }
    }
    cout<<"Minimum number: "<<mini<<"\n";
    cout<<"Maximum number: "<<maxi<<"\n";
    return;
}
int main(){
    int arr[3][3]={{1,2,3},{4,5,6},{7,8,9}};  // Initialization of 2d array
    int n=3;
    int key=5;
    minMax(arr,n);
    return 0;
}