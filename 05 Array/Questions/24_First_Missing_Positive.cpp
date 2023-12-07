#include<iostream>
#include <unordered_map>
#include<vector>
using namespace std;
int main(){
    int nums[7]={1,2,4,6,8,9,10};
    unordered_map<int,bool> map;
    for(int i=0;i<7;i++){ 
        map[nums[i]]=true;
    }
    for(int i=1;i<7;i++){
        if(map[i]==false){
            cout<<"Answer is "<<i;
            break;
        }
    }
    return 0;
}