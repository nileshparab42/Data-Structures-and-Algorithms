#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
    Node(){
        this->data=0;
        left=NULL;
        right=NULL;
    }
};

Node* preorderInsertion(){
    int data;
    cout<<"Enter Data \n";
    cin>>data;
    if(data==-1){
        return NULL;
    }
    Node* root=new Node(data);
    cout<<"Enter left node of "<<data<<" ";
    root->left=preorderInsertion();
    cout<<"Enter right node of "<<data;
    root->right=preorderInsertion();
    return root;
}

int HeightOfBinaryTree(Node* root) {
        if(root==NULL){
            return 0;
        }
        int leftheight = HeightOfBinaryTree(root->left);
        int rightheight = HeightOfBinaryTree(root->right);
        int ans = max(leftheight,rightheight)+1;
        return ans;
    }
int diameterOfBinaryTree(Node* root) {
        if(root==NULL){
            return 0;
        }
        int withroot = HeightOfBinaryTree(root->left)+HeightOfBinaryTree(root->right);
        int leftans = diameterOfBinaryTree(root->left);
        int rightans = diameterOfBinaryTree(root->right);
        return max(withroot,(max(leftans,rightans)));
    }

int main(){
    Node* root = preorderInsertion();
    diameterOfBinaryTree(root);
    return 0;
}