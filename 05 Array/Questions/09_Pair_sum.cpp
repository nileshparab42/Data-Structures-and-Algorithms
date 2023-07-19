#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> arr{1,2,3,4,5};
    vector<int> brr{4,5,6,7};
    int sum=9;
    for(int i=0; i<arr.size();i++){
        for(int j=0; j<brr.size();j++){
            if(sum==arr[i]+brr[j]){
                cout<<"("<<arr[i]<<","<<brr[j]<<")"<<endl;
            }
        }
    }
    return 0;
}