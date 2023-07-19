#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> arr{1,2,3,4,5};
    vector<int> brr{4,5,6,7};
    vector<int> crr{6,7,8,9};
    int sum=12;
    for(int i=0; i<arr.size();i++){
        for(int j=0; j<brr.size();j++){
            for(int k=0; k<crr.size();k++){
                if(sum==arr[i]+brr[j]+crr[k]){
                    cout<<"("<<arr[i]<<","<<brr[j]<<","<<crr[k]<<")"<<endl;
                }
            }
        }
    }
    return 0;
}