class Solution {
public:
    int rec(vector<int>& coins, int amount) {
        if(amount==0){
            return 0;
        }
        if(amount<0){
            return INT_MAX;
        }
        int mini=INT_MAX;
        for(int i=0;i<coins.size();i++){
            int ans = rec(coins,amount-coins[i]);
            if(ans!=INT_MAX){
                mini=min(mini,ans)+1;
            }
        }
        return mini;
    }

    int mem(vector<int>& coins, int amount,vector<int>& dp) {
        if(amount==0){
            return 0;
        }
        if(amount<0){
            return INT_MAX;
        }
        if(dp[amount] != -1){
            return dp[amount];
        }
        
        int mini=INT_MAX;
        for(int i=0;i<coins.size();i++){
            int ans = mem(coins,amount-coins[i],dp);
            if(ans!=INT_MAX){
                mini=min(mini,ans+1);
            }
        }
        dp[amount] = mini;
        return dp[amount];
    }

     int tab(vector<int>& coins, int finalamt) {
        vector<int> dp(finalamt+10,-1);
        dp[0]=0;
        for(int amount=1;amount<=finalamt;amount++){
            int mini=INT_MAX;
            for(int j=0;j<coins.size();j++){
                if(amount-coins[j]>=0 && amount-coins[j]<dp.size()){
                    int ans = dp[amount-coins[j]];
                    if(ans!=INT_MAX){
                        mini=min(mini,ans+1);
                    }
                }
            }
            dp[amount] = mini;
        }
        return dp[finalamt];
    }


    int coinChange(vector<int>& coins, int amount) {
        // int ans = rec(coins,amount);
        // if(ans==INT_MAX){
        //     return -1;
        // }else{
        //     return ans;
        // }
        // vector<int> dp(amount+10,-1);
        // int ans = mem(coins,amount,dp);
        // if(ans==INT_MAX){
        //     return -1;
        // }else{
        //     return ans;
        // }
        int ans =  tab(coins,amount);
        if(ans==INT_MAX){
            return -1;
        }else{
            return ans;
        }
    }
};