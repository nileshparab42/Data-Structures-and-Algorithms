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

    TreeNode* preinBuilt(vector<int>& preorder,vector<int>& inorder,int& size,int inStart,int inEnd,int& prepos){
        if(prepos>=size || inStart>inEnd){
            return NULL;
        }
        int element = preorder[prepos];
        prepos=prepos+1;
        cout<<prepos<<" "<<size<<"\n";
        TreeNode* root = new TreeNode(element);

        int position = inorderPos(element,inorder,size);
        root->left = preinBuilt(preorder,inorder,size,inStart,position-1,prepos);
        root->right = preinBuilt(preorder,inorder,size,position+1,inEnd,prepos);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int size = preorder.size();
        int inStart=0;
        cout<<size<<"\n";
        int inEnd=size-1;
        int prepos=0;
        TreeNode* root = preinBuilt(preorder,inorder,size,inStart,inEnd,prepos);
        return root;
    }
};