class Solution {
public:
    bool solve(vector<int>& nums,int i,int targetsum,vector<vector<int>>& dp){
        if(i>=nums.size()){
            return false;
        }
        if(targetsum<0){
            return false;
        }
        if(targetsum==0){
            return true;
        }
        if(dp[i][targetsum]!=-1){
            return dp[i][targetsum];
        }
        bool inclusion = solve(nums,i+1,targetsum-nums[i],dp);
        bool exclusion = solve(nums,i+1,targetsum,dp);
        dp[i][targetsum] = (inclusion||exclusion);
        return dp[i][targetsum];
    }

    bool solvetab(vector<int>& nums,int& sum){
        vector<vector<int>> dp(nums.size()+1,vector<int>(sum+1,0));
        for(int i=0;i<nums.size();i++){
            dp[i][0] = 1; 
        }
        for(int i=nums.size()-1;i>=0;i--){
            for(int targetsum=1;targetsum<=sum;targetsum++){
                bool inclusion=0;
                if(targetsum-nums[i]>=0)
                    inclusion = dp[i+1][targetsum-nums[i]];
                bool exclusion = dp[i+1][targetsum];
                dp[i][targetsum] = (inclusion||exclusion);
            }
        }
        return dp[0][sum];
    }

    bool SO(vector<int>& nums,int& sum){
        vector<vector<int>> dp(nums.size()+1,vector<int>(sum+1,0));
        vector<int> curr(sum+1,0);
        vector<int> next(sum+1,0);
        curr[0]=1;
        next[0]=1;
        for(int i=nums.size()-1;i>=0;i--){
            for(int targetsum=1;targetsum<=sum;targetsum++){
                bool inclusion=0;
                if(targetsum-nums[i]>=0)
                    inclusion = next[targetsum-nums[i]];
                bool exclusion = next[targetsum];
                curr[targetsum] = (inclusion||exclusion);
            }
            next=curr;
        }
        return next[sum];
    }
    bool canPartition(vector<int>& nums) {
        int targetsum = 0;
        for(auto i:nums){
            targetsum+=i;
        }
        if(targetsum&1){
            return false;
        }
        targetsum/=2;
        // vector<vector<int>> dp(nums.size(),vector<int>(targetsum+1,-1));
        // return solve(nums,0,targetsum,dp);
        bool ans = SO(nums,targetsum);
        return ans;
    }

};