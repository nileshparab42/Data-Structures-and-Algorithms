#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

class Nodedata{
    public:
    int size;
    int min;
    int max;
    bool valid;

    Nodedata(){

    }

    Nodedata(int size,int min,int max,bool valid){
        this->size=size;
        this->min=min;
        this->max=max;
        this->valid=valid;
    }
};

Nodedata* solve(TreeNode<int>* root,int& ans){
    if(root==NULL){
        Nodedata* temp=new Nodedata(0,INT_MAX,INT_MIN,true);
        return temp;
    }
    Nodedata* leftnode = solve(root->left,ans);
    Nodedata* rightnode = solve(root->right,ans);
    int currsize = (leftnode->size+rightnode->size+1);
    int currmin = min(root->data,leftnode->min);
    int currmax = max(root->data,rightnode->max);
    bool currval;
    if(leftnode->valid && rightnode->valid && root->data > leftnode->max && root->data < rightnode->min){
        currval=true;
        if(currsize>=ans){
            ans=currsize;
            
        }
    } 
    else{
        currval=false;
    }
    Nodedata* temp = new Nodedata(currsize,currmin,currmax,currval);
    return temp;
}

int largestBST(TreeNode<int>* root) 
{
    int ans=INT_MIN;
    solve(root,ans);
    return ans;
}
