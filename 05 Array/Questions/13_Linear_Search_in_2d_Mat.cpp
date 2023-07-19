#include<iostream>
using namespace std;
bool linearSearch(int arr[][3],int n,int key){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]==key) 
                return true;
        }
    }
    return false;
}
int main(){
    int arr[3][3]={{1,2,3},{4,5,6},{7,8,9}};  // Initialization of 2d array
    int n=3;
    int key=5;
    if(linearSearch(arr,n,key)==true){
        cout<<"Element is present";
    }
    else{
        cout<<"Element is not present";
    }
    return 0;
}