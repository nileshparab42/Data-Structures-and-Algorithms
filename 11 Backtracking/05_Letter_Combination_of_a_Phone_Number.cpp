class Solution {
public:
    void solve(string& digits,vector<string>& map,int index,vector<string>& ans,string output){
        if(index>=digits.length()){
            ans.push_back(output);
            return;
        }
        int digit = digits[index]-'0';
        string value=map[digit];
        for(int i=0;i<value.length();i++){
            output.push_back(value[i]);
            solve(digits,map,index+1,ans,output);
            output.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {

        int index=0;
        vector<string> ans;
        string output="";

        if(digits.length()==0){
            return ans;
        }

        vector<string> map(10);
        map[2]="abc";
        map[3]="def";
        map[4]="ghi";
        map[5]="jkl";
        map[6]="mno";
        map[7]="pqrs";
        map[8]="tuv";
        map[9]="wxyz";

        solve(digits,map,index,ans,output);
        return ans;
    }
};