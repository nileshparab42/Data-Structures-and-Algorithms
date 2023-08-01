class solve{
    public:
    //Function to return the maximum sum of non-adjacent nodes.
    pair<int,int> solve(Node* root){
        if(root==NULL){
            pair<int,int> temp = make_pair(0,0);
            return temp;
        }
        pair<int,int> a = solve(root->left);
        pair<int,int> b = solve(root->right);
        //include
        int i = root->data+a.second+b.second;
        int x = max(a.first,a.second) + max(b.first,b.second);
        pair<int,int> temp = make_pair(i,x);
        return temp;
    }
    int getMaxSum(Node *root) 
    {
        // Add your code here
        pair<int,int> ans = solve(root);
        return max(ans.first,ans.second);
    }
};