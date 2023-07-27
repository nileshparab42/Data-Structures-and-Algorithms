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
    bool increasing(vector<int>& ans){
        if(ans.size()==1){
            if(ans[0] % 2 ==0){
                return false;
            }
            else{
                return true;
            }
        }
        for(int i=0;i<ans.size()-1;i++){
            if(ans[i]%2==0 || ans[i+1]%2==0){
                return false;
            }
            if(ans[i] >= ans[i+1]){
                return false;
            }
        }
        return true;
    }
    bool decreasing(vector<int> ans){
        if(ans.size()==1){
            if(ans[0] % 2 !=0){
                return false;
            }
            else{
                return true;
            }
        }
        for(int i=0;i<ans.size()-1;i++){
            if(ans[i]%2!=0 || ans[i+1]%2!=0){
                return false;
            }
            if(ans[i] <= ans[i+1]){
                return false;
            }
        }
        return true;
    }
    void lvltrav(TreeNode* root,vector<bool>& valid){
        vector<int> ans;
        int lvl=0;
        queue<TreeNode*> q;
        q.push(root);

       if(root->val % 2 ==0){
           valid.push_back(false);
       }
       else{
           valid.push_back(true);
       }

        q.push(NULL);
        while(!q.empty()){
            TreeNode* temp = q.front();

            if(temp==NULL){
                q.pop();
                cout<<"\n";

                if(lvl%2==0){
                    valid.push_back(increasing(ans));
                }else{
                    valid.push_back(decreasing(ans));
                }
                ans.clear();
                if(!q.empty()){
                    q.push(NULL);
                }
                lvl++;
            }
            if(temp!=NULL){
                cout<<temp->val<<" ";
                ans.push_back(temp->val);
                q.pop();
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
        }
    }
    bool isEvenOddTree(TreeNode* root) {
        vector<bool> valid;
        lvltrav(root,valid);
        for(int i=0;i<valid.size();i++){
            cout<<valid[i];
            if(valid[i]==false){
                return false;
            }
        }
        return true;
    }
};