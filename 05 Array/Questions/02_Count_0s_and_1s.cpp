#include<iostream>
#include<string.h>
using namespace std;

void CountZerosAndOnes(int arr[],int size){
    int czero=0;
    int cone=0;
    for(int i=0;i<size;i++){
        if(arr[i]==0)
            czero++;
        if(arr[i]==1)
            cone++;
    }
    cout<<"Number of zeros: "<<czero<<endl;
    cout<<"Number of ones: "<<cone<<endl;
}

int main(){
    int arr[7]={0,0,1,0,1,1,0};
    CountZerosAndOnes(arr,7);
}