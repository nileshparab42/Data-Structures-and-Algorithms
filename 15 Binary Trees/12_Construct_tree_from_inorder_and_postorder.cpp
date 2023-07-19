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

    
    int inorderPos(int element,vector<int>& inorder,int size){
        for(int i=0;i<size;i++){
            if(inorder[i]==element){
                return i;
            }
        }
        return -1;
    }

    TreeNode* postinBuilt(vector<int>& postorder,vector<int>& inorder,int& size,int inStart,int inEnd,int& postpos){
        if(postpos<0 || inStart>inEnd){
            return NULL;
        }
        int element = postorder[postpos];
        postpos=postpos-1;
        TreeNode* root = new TreeNode(element);

        int position = inorderPos(element,inorder,size);
        
        root->right = postinBuilt(postorder,inorder,size,position+1,inEnd,postpos);
        root->left = postinBuilt(postorder,inorder,size,inStart,position-1,postpos);

        return root;
    }


    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int size = postorder.size();
        int inStart=0;
        int inEnd=size-1;
        int postpos=size-1;
        TreeNode* root = postinBuilt(postorder,inorder,size,inStart,inEnd,postpos);
        return root;
    }

};