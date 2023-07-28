class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        priority_queue<int> maxheap;
        for(int i=0;i<nums1.size();i++){
            maxheap.push(nums1[i]);
        }
        for(int i=0;i<nums2.size();i++){
            maxheap.push(nums2[i]);
        }
        int m=nums1.size();
        int n=nums2.size();
        int z=m+n;
        float ans;
        if(z%2==0){
            int count=(z/2)-1;
            while(count--){
                maxheap.pop();
            }
            float temp1=maxheap.top();
            maxheap.pop();
            float temp2=maxheap.top();
            cout<<temp1<<" "<<temp2;
            ans=(temp1+temp2)/2;
        }else{
            int count=z/2;
            while(count--){
                maxheap.pop();
            }
            ans=maxheap.top();
        }
        return ans;
    }
};