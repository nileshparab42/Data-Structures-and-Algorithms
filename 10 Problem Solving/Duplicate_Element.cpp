#include <iostream>
using namespace std;

int main() {
  int arr[8]={2,4,3,1,5,5,7,8};
  int i=0;
  int n=8;
  while(i<n){
    if(arr[i]-1==i){
      i++;
    }
    if(arr[i]!=arr[arr[i]-1]){
      swap(arr[i],arr[arr[i]-1]);
    }
    if(arr[arr[i]-1]==arr[i] && arr[i]-1!=i){
      cout<<"Ans: "<<arr[i]<<"\n";
      break;
    }
  }
  return 0;
}