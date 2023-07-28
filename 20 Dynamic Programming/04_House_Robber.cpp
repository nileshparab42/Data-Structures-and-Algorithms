class Solution {
public:
    int rec(vector<int>& nums,int i) {
        //base case
        if(i>=nums.size()){
            return 0;
        }
        int include = nums[i] + rec(nums,i+2);
        int exclude = 0 + rec(nums,i+1);
        return max(include,exclude);
    }
    int mem(vector<int>& nums,int i,vector<int>& dp) {
        //base case
        if(i>=nums.size()){
            return 0;
        }
        if(dp[i]!=INT_MIN){
            return dp[i];
        }
        int include = nums[i] + mem(nums,i+2,dp);
        int exclude = 0 + mem(nums,i+1,dp);
        dp[i] = max(include,exclude);
        return dp[i];
    }
    int tab(vector<int>& nums) {
        vector<int> dp(nums.size()+2,INT_MIN);
        //base case
        dp[nums.size()]=0;
        dp[nums.size()+1]=0;
        for(int i=nums.size()-1;i>=0;i--){
            int include = nums[i] + dp[i+2];
            int exclude = 0 + dp[i+1];
            dp[i] = max(include,exclude);
        }
        
        return dp[0];
    }

    int spaceop(vector<int>& nums) {
        int next1=0;
        int next2=0;
        int curr;
        for(int i=nums.size()-1;i>=0;i--){
            int include = nums[i] + next2;
            int exclude = 0 + next1;
            curr = max(include,exclude);
            next2=next1;
            next1=curr;
        }
        return curr;
    }
    int rob(vector<int>& nums) {
        // return rec(nums,0);
        //create dp array;
        // vector<int> dp(nums.size()+1,INT_MIN);
        // return mem(nums,0,dp);
        return spaceop(nums);
    }
};