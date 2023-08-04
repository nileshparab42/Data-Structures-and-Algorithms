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
    void solve(TreeNode* root,string output,vector<string>& nums){
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
            nums.push_back(output+to_string(root->val));
            return;
        }
        solve(root->left,output+to_string(root->val),nums);
        solve(root->right,output+to_string(root->val),nums);
    }
    int sumNumbers(TreeNode* root) {
        vector<string> nums;
        solve(root,"",nums);
        int ans=0;
        for(auto i:nums){
            cout<<i<<" ";
            ans+=stoi(i);
        }
        return ans;
    }
};