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
    bool solve(TreeNode* root,int& k) {
        if(root==NULL){
            return true;
        }
        bool leftans = solve(root->left,k);
        bool rightans = solve(root->right,k);
        return leftans && rightans && root->val==k;
    }
    bool isUnivalTree(TreeNode* root) {
        int k=root->val;
        bool leftans = solve(root->left,k);
        bool rightans = solve(root->right,k);
        return leftans && rightans;
    }
};