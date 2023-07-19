class Solution {
public:
    void solve(int n,int open,int close,vector<string>& ans,string output){
        if(open==0 && close==0){
            ans.push_back(output);
            return;
        }
        //include open bracket
        if(open>0){
            output.push_back('(');
            solve(n,open-1,close,ans,output);
            output.pop_back();
        }
        if(close>open){
            output.push_back(')');
            solve(n,open,close-1,ans,output);
            output.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        int n=3;
        vector<string> ans;
        int open=n;
        int close=n;
        string output="";
        solve(n,open,close,ans,output);
        return ans;
    }
};