#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> arr{1,2,3,4,5};
    vector<int> brr{4,5,6,7};
    vector<int> ans;

    for(int i=0; i<arr.size();i++){
        for(int j=0; j<brr.size();j++){
            if(arr[i]==brr[j]){
                ans.push_back(arr[i]);
            }
        }
    }
    
    for(auto i: ans){
        cout<<i<<" ";
    }
 
    return 0;
}