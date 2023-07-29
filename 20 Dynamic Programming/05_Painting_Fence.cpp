class solution{
    public:
    long long rec(int n, int k){
        // code here
        if(n==1){
            return k;
        }
        if(n==2){
            return (k+k*(k-1));
        }
        long long ans = (rec(n-2,k)+rec(n-1,k))*(k-1);
    
        return ans;
    }
    int solveUsingMem(int n, int k, vector<long long>& dp)  {
      if(n == 1) {
        return k ;
      }
      if(n == 2) {
        return (k + k*(k-1));
      }
    
      if(dp[n] != -1)
        return dp[n];
    
      dp[n]  = (solveUsingMem(n-2,k,dp) + solveUsingMem(n-1,k,dp))*(k-1);
      return dp[n];
    }
    long long countWays(int n, int k){
        // code here
        vector<long long> dp(n+1,-1);
        long long ans = solveUsingMem(n,k,dp);
        return ans;
    }
};