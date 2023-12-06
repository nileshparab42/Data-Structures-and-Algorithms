#include<iostream>
#include <unordered_map>
#include<vector>
using namespace std;
int main(){
    int nums[7]={1,5,3,4,3,5,6};
    unordered_map<int,int> map;
    for(int i=0;i<7;i++){
        
        map[nums[i]]++;
    }
    for(int i=0;i<7;i++){
        if(map[nums[i]]>1){
            cout<<"Answer is "<<nums[i];
            break;
        }
    }
    return 0;
}