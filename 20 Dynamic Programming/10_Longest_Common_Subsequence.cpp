class Solution {
public:
    int solveRec(string a,string b,int i,int j){
        if(i>=a.length()){
            return 0;
        }
        if(j>=b.length()){
            return 0;
        }
        if(a[i]==b[j]){
            return 1+solveRec(a,b,i+1,j+1);
        }
        int ans = 0;
        if(a[i]!=b[j]){
            ans = max(solveRec(a,b,i,j+1),solveRec(a,b,i+1,j));
        }
        return ans;
    }
    int solveMem(string& a,string& b,int i,int j,vector<vector<int>>& dp){
        if(i>=a.length()){
            return 0;
        }
        if(j>=b.length()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(a[i]==b[j]){
            return 1+solveMem(a,b,i+1,j+1,dp);
        }
        int ans = 0;
        if(a[i]!=b[j]){
            ans = max(solveMem(a,b,i,j+1,dp),solveMem(a,b,i+1,j,dp));
        }
        dp[i][j] = ans;
        return dp[i][j];
    }
    int solveTab(string a, string b){
        vector<vector<int>> dp(a.length()+10,vector<int>(b.length()+10,0));
        for(int i=a.length()-1;i>=0;i--){
            for(int j=b.length()-1;j>=0;j--){
                int ans = 0;
                if(a[i]==b[j]){
                    ans =  1+dp[i+1][j+1];
                }
                if(a[i]!=b[j]){
                    ans = max(dp[i][j+1],dp[i+1][j]);
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }
    int longestCommonSubsequence(string text1, string text2) {
        // return solveRec(text1,text2,0,0);
        vector<vector<int>> dp(text1.length()+10,vector<int>(text2.length()+10,-1));
        return solveTab(text1,text2);
    }
};