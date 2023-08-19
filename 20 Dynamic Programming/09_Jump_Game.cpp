class Solution {
public:
    bool solverec(vector<int>& nums,int i){
        if(i>=nums.size()-1){
            return true;
        }
        if(nums[i]==0){
            return false;
        }
        bool ans = false;
        for(int j=1;j<=nums[i];j++){
            ans = (ans || solverec(nums,i+j));
        }
        return ans;
    }

    bool solvemem(vector<int>& nums,int i,vector<int>& dp){
        if(i>=nums.size()-1){
            return true;
        }
        if(nums[i]==0){
            return false;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        bool ans = false;
        for(int j=1;j<=nums[i];j++){
            ans = (ans || solvemem(nums,i+j,dp));
        }
        dp[i] = ans;
        return dp[i];
    }
    bool solvetab(vector<int>& nums) {
        vector<int> dp(nums.size()+100,0);
        for(int z=nums.size()-1;z<dp.size();z++){
            dp[z]=1;
        }
        for(int i=nums.size()-2;i>=0;i--){
            bool ans = false;
            for(int j=1;j<=nums[i];j++){
                if(i+j <nums.size()){
                    ans = (ans || dp[i+j]);
                }
            }
            dp[i] = ans;
        }
        return dp[0];
    }
    bool canJump(vector<int>& nums) {
        // return solverec(nums,0);
        vector<int> dp(nums.size()+10,-1);
        return solvetab(nums);
    }
};