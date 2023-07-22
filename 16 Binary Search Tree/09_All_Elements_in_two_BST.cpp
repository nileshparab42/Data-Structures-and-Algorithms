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
    void inorder(TreeNode* root,priority_queue<int,vector<int>,greater<int>>& minheap){
        if(root==NULL){
            return;
        }
        inorder(root->left,minheap);
        minheap.push(root->val);
        inorder(root->right,minheap);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        priority_queue<int,vector<int>,greater<int>> minheap;
        inorder(root1,minheap);
        inorder(root2,minheap);
        vector<int> ans;
        while(!minheap.empty()){
            int temp=minheap.top();
            minheap.pop();
            ans.push_back(temp);
        }
        return ans;
    }
};