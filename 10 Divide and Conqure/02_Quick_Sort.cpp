#include<iostream>
using namespace std;

int partition(int* arr,int s,int e){
    int pipos=s;
    int piele=arr[s];
    int count=0;
    for(int i=s+1;i<=e;i++){
        if(arr[i]<=piele){
            count++;
        }
    }
    int rightplace=s+count;
    swap(arr[pipos],arr[rightplace]);
    pipos=rightplace;
    int i=s;
    int j=e;
    while(i<pipos && j>pipos){
        if(arr[i]<=arr[pipos]){
            i++;
        }
        if(arr[j]>arr[pipos]){
            j--;
        }
        swap(arr[i],arr[j]);
    }
    return pipos;
}

void quickSort(int* arr,int s,int e){
    if(s>=e){
        return;
    }
    int p=partition(arr,s,e);
    quickSort(arr,s,p-1);
    quickSort(arr,p+1,e);

}

int main(){
    int arr[]={8,3,4,1,20,50,30};
    quickSort(arr,0,6);
    for(auto i:arr){
        cout<<i<<" ";
    }
    return 0;
}