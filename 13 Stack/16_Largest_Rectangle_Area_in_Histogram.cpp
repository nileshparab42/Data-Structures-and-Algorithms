#include<iostream>
#include<stack>
#include<vector>
#include<limits.h>
using namespace std;

void nextSmallerElement(vector<int>& nums,int& size, vector<int>& nextSmall) {
    stack<int> st;
    st.push(-1);
    for(int i=size-1;i>=0;i--){
        int ele=nums[i];
        while(st.top()!=-1 && nums[st.top()]>=ele){
            st.pop();
        }
        nextSmall[i]=st.top();
        st.push(i);
    }
    return;
}

    void previousSmallest(vector<int>& nums,int& size, vector<int>& prevSmall) {
    stack<int> st;
    st.push(-1);
    for(int i=0;i<size;i++){
        int ele=nums[i];
        while(st.top()!=-1 && nums[st.top()]>=ele){
            st.pop();
            }
        prevSmall[i]=st.top();
        st.push(i);
        }
    return;
    }


    int largestRectangleArea(vector<int>& heights) {
        int size=heights.size();
        vector<int> nextSmall(size);
        vector<int> prevSmall(size);
        nextSmallerElement(heights,size,nextSmall); 
        previousSmallest(heights,size,prevSmall);
        int maxArea=INT_MIN;


        for(int i=0;i<size;i++){
            int l=heights[i];
            int n=nextSmall[i];
            int p=prevSmall[i];
            if(n==-1){
                n=size;
            }
            int currArea=(l)*(n-p-1);
            // b=n-p-1
            // currArea=l*b;
            maxArea=max(maxArea,currArea);
        }

        return maxArea;
    }


int main(){
    // [2,1,5,6,2,3]
    vector<int> heights;
    heights.push_back(2);
    heights.push_back(1);
    heights.push_back(5);
    heights.push_back(6);
    heights.push_back(2);
    heights.push_back(3);
    cout<<largestRectangleArea(heights); 
    return 0;
}