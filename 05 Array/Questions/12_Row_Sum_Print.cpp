#include<iostream>
using namespace std;
int main(){
    int arr[3][3]={{1,2,3},{4,5,6},{7,8,9}};  // Initialization of 2d array
    int n=3;
    int ans=0;
    for(int i=0;i<n;i++){
        ans=0;
        for(int j=0;j<n;j++){
            ans+=arr[i][j];
        }
        cout<<ans<<" ";
    }
   
    return 0;
}