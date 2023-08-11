
/*The Node structure is
struct Node {
int data;
Node * right, * left;
};*/

/*You are required to complete below method */
void solve(Node *root,unordered_map<int,bool>& map,bool& ans){
    if(root==NULL){
        return;
    }
    map[root->data]=true;
    int plus = root->data + 1;
    int minus = (root->data - 1)<=0 ? root->data:root->data - 1;
    if(map[minus]==true && map[plus]==true){
        ans=true;
    }
    solve(root->left,map,ans);
    solve(root->right,map,ans);
}

bool isDeadEnd(Node *root)
{
    //Your code here
    unordered_map<int,bool> map;
    bool ans=false;
    solve(root,map,ans);
    return ans;
}