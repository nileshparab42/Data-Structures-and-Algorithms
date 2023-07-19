#include<iostream>
#include<stack>
#include<vector>
using namespace std;

void previousSmallest(vector<int>& nums,int& size, vector<int>& ans) {
    stack<int> st;
    st.push(-1);
    for(int i=0;i<size;i++){
        int ele=nums[i];
        while(st.top()>=ele){
            st.pop();
        }
        ans[i]=st.top();
        st.push(ele);
    }
    return;
}

int main(){
    vector<int> nums;
    vector<int> ans(4);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(4);
    nums.push_back(3);
    int size=4;
    previousSmallest(nums,size,ans);
    for(int i=0;i<size;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}