class Solution {
public:

    int recSolve(int n){
        if(n==0 || n==1){
            return 1;
        }
        return recSolve(n-1)+recSolve(n-2);
    }

    int topDownSolve(int n,unordered_map<int,int> dp){
        if(n==0 || n==1){
            return 1;
        }
        if(dp.find(n)!=dp.end()){
            return dp[n];
        }
        dp[n] = recSolve(n-1)+recSolve(n-2);
        return dp[n];
    }

    int bottomupSolve(int n,unordered_map<int,int> dp){
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }

    int spaceOptimization(int n,unordered_map<int,int> dp){
        if(n==0 || n==1){
            return 1;
        }
        int prev1 = 1;
        int prev2 = 1;
        int curr;
        for(int i=2;i<=n;i++){
            curr=prev2+prev1;
            prev2=prev1;
            prev1=curr;
        }
        return curr;
    }

    int climbStairs(int n) {
        unordered_map<int,int> dp;
        return spaceOptimization(n,dp);
    }
};