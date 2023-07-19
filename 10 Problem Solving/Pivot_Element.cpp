#include <iostream>
using namespace std;
int pivot(int* arr,int n){
  int s=0;
  int e=n-1;
  int mid=s+(e-s)/2;
  while(s<e){
    if(arr[mid]>arr[mid+1]){
      return mid;
    }
    if(arr[mid]<arr[s]){
      e=mid-1;
    }
    if(arr[mid]>=arr[s]){
      s=mid+1;
    }
  mid=s+(e-s)/2;
  }
}
int main() {
  int arr[10]={4,5,6,7,8,9,1,2,3};
  cout<<pivot(arr,10);
  
  return 0;
}