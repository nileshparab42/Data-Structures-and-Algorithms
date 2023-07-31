class solution{
    public:
    pair<int,int> solve(Node* root){
        if(root==NULL){
            pair<int,int> temp = make_pair(0,0);
            return temp;
        }
        pair<int,int> left=solve(root->left);
        pair<int,int> right=solve(root->right);
        if(right.first>=left.first){
            pair<int,int> temp;
            temp.first=right.first+1;
            temp.second=root->data+right.second;
            return temp;
        }
        else{
            pair<int,int> temp;
            temp.first=left.first+1;
            temp.second=root->data+left.second;
            return temp;
        }
    }
    int sumOfLongRootToLeafPath(Node *root)
    {
        //code here
        pair<int,int> ans = solve(root);
        return ans.second;
    }
};