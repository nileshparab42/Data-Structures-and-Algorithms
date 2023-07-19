#include<iostream>
using namespace std;

void heapify(int arr[],int& len,int index){
        if(index>len){
            return;
        }
        int left=index*2;
        int right=(index*2)+1;
        int largeindex = index;
        if(left<=len && arr[left]>arr[largeindex]){
            largeindex=left;
        }
        if(right<=len && arr[right]>arr[largeindex]){
            largeindex=right;
        }
        if(largeindex!=index){
            swap(arr[largeindex],arr[index]);
            heapify(arr,len,largeindex);
        }
        else{
            return;
        }
    }


void buildHeap(int arr[],int& n){
    int startindex = n/2;
    for(int i=startindex;i>0;i--){
        heapify(arr,n,i);
    }
}

void heapSort(int arr[],int n){
    while(n!=1){
        swap(arr[1],arr[n]);
        n=n-1;
        heapify(arr,n,1);
    }
}



int main(){

    int arr[13]={-1,12,56,43,6,78,87,5,44,3,23,32};
    int len=12;
    buildHeap(arr,len);
    heapSort(arr,len);
    for(int i=1;i<=len;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}