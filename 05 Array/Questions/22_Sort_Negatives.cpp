#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;
int main(){
    int nums[5]={-1,2,3,-2,5};
    int l=0;
    int h=4;
    while(l<h){
        if(nums[l]<0){
            l++;
        }
        if(nums[h]>0){
            h--;
        }
        swap(nums[l],nums[h]);
    }
    for(auto i:nums){
        cout<<i<<" ";
    }
    return 0;
}