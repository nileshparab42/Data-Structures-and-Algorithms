/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root,vector<int> parval,int& ans){
        if(root==NULL){
            return;
        }
        int maxi=INT_MIN;
        parval.push_back(root->val);
        for(int i=0;i<parval.size();i++){
            if(maxi<parval[i]){
                maxi=parval[i];
            }
        }
        if(maxi==root->val){
            ans++;
        }
        solve(root->left,parval,ans);
        solve(root->right,parval,ans);
    }
    int goodNodes(TreeNode* root) {
        int ans=0;
        vector<int> parval;
        solve(root,parval,ans);
        return ans;        
    }
};