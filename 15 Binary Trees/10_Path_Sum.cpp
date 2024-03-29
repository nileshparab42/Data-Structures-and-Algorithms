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
    void solve(TreeNode* root, int& targetSum,vector<vector<int>>& ans,int& currSum,vector<int> temp){
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
            currSum+=root->val;
            temp.push_back(root->val);
            if(currSum==targetSum){
                ans.push_back(temp);
            }
            currSum-=root->val;
            temp.pop_back();
            return;
        }
        currSum+=root->val;
        temp.push_back(root->val);
        solve(root->left, targetSum,ans,currSum,temp);
        solve(root->right, targetSum,ans,currSum,temp);
        currSum-=root->val;
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> temp;
        int currSum=0;
        solve(root, targetSum,ans,currSum,temp);
        return ans;
    }
};