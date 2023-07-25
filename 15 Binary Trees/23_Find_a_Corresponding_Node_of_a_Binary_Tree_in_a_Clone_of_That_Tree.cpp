/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    void solve(TreeNode* original, TreeNode* cloned, TreeNode* target,TreeNode*& ans) {
        if(cloned ==NULL){
            return;
        }
        if(cloned->val==target->val){
            ans= cloned;
        }
        solve(original, cloned->left,target,ans);
        solve(original, cloned->right,target,ans);
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode* ans=NULL;
        solve(original, cloned,target,ans);
        return ans;
    }
};