class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> copy = heights;
        int ans=0;
        sort(copy.begin(),copy.end());
        for(int i=0;i<copy.size();i++){
            if(copy[i]!=heights[i]){
                ans++;
            }
        }
        return ans;
    }
};