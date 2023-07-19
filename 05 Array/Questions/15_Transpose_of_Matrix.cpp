#include<iostream>
#include<limits.h>
using namespace std;
void transpose(int arr[][3],int brr[][3],int n){
    int mini=INT_MAX;
    int maxi=INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            brr[i][j]=arr[j][i];
        }
    }
    return;
}
int main(){
    int arr[3][3]={{2,4,6},{1,3,5},{9,11,13}};  // Initialization of 2d array
    int brr[3][3];
    int n=3;
    int key=5;
    transpose(arr,brr,n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<brr[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}