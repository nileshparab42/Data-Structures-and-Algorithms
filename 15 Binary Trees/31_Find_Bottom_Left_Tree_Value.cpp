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
    int solve(TreeNode* root,vector<int>& ans){
        if(root==NULL){
            return -1;
        }
        if(root->left==NULL && root->right==NULL){
            return root->val;
        }
        queue<TreeNode*> q;
        int leftist=-1;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            TreeNode* temp=q.front();
            q.pop();
            if(temp==NULL){
                cout<<"\n";
                leftist=ans[0];
                for(int i=0;i<ans.size();i++){
                    cout<<ans[i]<<" ";
                }
                ans.clear();
                cout<<"\n";
                if(!q.empty()){
                    q.push(NULL);
                }
            }
            else{
                if(temp->left!=NULL){
                    q.push(temp->left);
                    ans.push_back(temp->left->val);
                }
                if(temp->right!=NULL){
                    q.push(temp->right);
                    ans.push_back(temp->right->val);
                }
            }
        }
        return leftist;
    }
    int findBottomLeftValue(TreeNode* root) {
        vector<int> ans;
        int leftist = solve(root,ans);
        cout<<"ans:"<<leftist;
        return leftist;
    }
};