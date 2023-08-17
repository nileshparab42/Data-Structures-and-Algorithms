class Solution {
public:
    int findlast(vector<int>& nums, int& target){
        int s=0;
        int e=nums.size()-1;
        int ans = -1;
        int mid=(s+e)/2;
        while(s<=e){
            if(nums[mid]==target){
                ans=mid;
                s=mid+1;
            }
            if(nums[mid]>target){
                e=mid-1;
            }
            if(nums[mid]<target){
                s=mid+1;
            }
            mid=(s+e)/2;
        }
        return ans;
    }
    int findfirst(vector<int>& nums, int& target){
        int s=0;
        int e=nums.size()-1;
        int ans = -1;
        int mid=(s+e)/2;
        while(s<=e){
            if(nums[mid]==target){
                ans=mid;
                e=mid-1;
            }
            if(nums[mid]>target){
                e=mid-1;
            }
            if(nums[mid]<target){
                s=mid+1;
            }
            mid=(s+e)/2;
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = findfirst(nums,target);
        int last = findlast(nums,target);
        vector<int> positions;
        positions.push_back(first);
        positions.push_back(last);
        return positions;
    }
};