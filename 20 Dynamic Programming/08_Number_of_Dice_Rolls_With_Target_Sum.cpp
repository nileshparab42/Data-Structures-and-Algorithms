class Solution {
public:
    int MOD = 1000000000+7;

    int solverec(int n, int& k, int target) {
        if(n<0){
            return 0;
        }   
        if(n==0 && target == 0){
            return 1;
        }
        if(n!=0 && target==0){
            return 0;
        }
        if(n==0 && target!=0){
            return 0;
        }
        int ans = 0;
        for(int i=1;i<=k;i++){
            ans += solverec(n-1, k, target-i); 
        }
        return ans;
    }


    long long int  solvemem(int n, int& k, int target,vector<vector<long long int >>& dp) {
        if(n<0){
            return 0;
        }   
        if(n==0 && target == 0){
            return 1;
        }
        if(n!=0 && target==0){
            return 0;
        }
        if(n==0 && target!=0){
            return 0;
        }
        if(dp[n][target]!=-1){
            return dp[n][target];
        }
        long long int ans = 0;
        for(int i=1;i<=k;i++){
            //Yaha Fasega
            if(target-i>=0){
                ans = ((ans%MOD) + solvemem(n-1, k, target-i,dp)%MOD)%MOD; 
            }
        }
        dp[n][target] = ans;
        return dp[n][target];
    }

    int solvetab(int m, int k, int tot){
        vector<vector<long long int >> dp(m+10,vector<long long int >(tot+10,0));
        dp[0][0] = 1;
        for(int n=1;n<=m;n++){
            for(int target=1;target<=tot;target++){
                long long ans=0;
                for(int i=1;i<=k;i++){
                    if(target-i>=0){
                        ans = ((ans%MOD) + (dp[n-1][target-i])%MOD)%MOD; 
                    }
                }
                dp[n][target]=ans;
            }
        }
        return dp[m][tot];

    }

    int solveSO(int m, int k, int tot){
        // vector<vector<long long int >> dp(m+10,vector<long long int >(tot+10,0));
        vector<long long int> prev(tot+10,0);
        vector<long long int> curr(tot+10,0);
        prev[0] = 1;
        for(int n=1;n<=m;n++){
            for(int target=1;target<=tot;target++){
                long long ans=0;
                for(int i=1;i<=k;i++){
                    if(target-i>=0){
                        ans = ((ans%MOD) + (prev[target-i])%MOD)%MOD; 
                    }
                }
                curr[target]=ans;
            }
            prev = curr;
        }
        return prev[tot];

    }

    long long int  numRollsToTarget(int n, int k, int target) {
        // int ans = solverec(n,k,target);

        vector<vector<long long int >> dp(n+10,vector<long long int >(target+10,-1));
        int  ans = solveSO(n,k,target);
        return ans;   
    }
};