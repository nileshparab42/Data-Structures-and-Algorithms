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

int heightofBt(Node* root){
        if(root==NULL){
            return 0;
        }
        int leftheight=heightofBt(root->left);
        int rightheight=heightofBt(root->right);
        return max(leftheight,rightheight)+1;
    }
    bool isBalanced(Node* root) {
        if (root==NULL){
            return true;
        }
        int leftheight=heightofBt(root->left);
        int rightheight=heightofBt(root->right);
        int diff=abs(leftheight-rightheight);
        bool currAns=(diff<=1);
        bool leftAns=isBalanced(root->left);
        bool rightAns=isBalanced(root->right);
        if(currAns&&leftAns&&rightAns){
            return true;
        }
        else{
            return false;
        }
    }

int main(){
    Node* root = preorderInsertion();
    isBalanced(root);
    return 0;
}