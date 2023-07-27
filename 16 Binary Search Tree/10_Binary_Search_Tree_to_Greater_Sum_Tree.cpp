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
    void solve(TreeNode* root,int& ans){
        if(root==NULL){
            return;
        }
        solve(root->right,ans);

        cout<<root->val<<"->"<<ans<<"\n";
        root->val = root->val + ans;
        ans= root->val;

        solve(root->left,ans);
    }
    TreeNode* bstToGst(TreeNode* root) {
        int ans=0;
        solve(root,ans);
        return root;
    }
};