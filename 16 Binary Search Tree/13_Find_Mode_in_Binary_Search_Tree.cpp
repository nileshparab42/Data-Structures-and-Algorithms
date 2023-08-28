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
    void solve(TreeNode* root,unordered_map<int,int>& fr){
        if(root==NULL){
            return;
        }
        fr[root->val]++;
        solve(root->left,fr);
        solve(root->right,fr);
    }
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        unordered_map<int,int> fr;
        solve(root,fr);
        int max=INT_MIN;
        for(auto i:fr){
            if(i.second>max){
                max=i.second;
            }
        }
        for(auto i:fr){
            if(i.second==max){
                ans.push_back(i.first);
            }
        }
        
        return ans;
    }
};