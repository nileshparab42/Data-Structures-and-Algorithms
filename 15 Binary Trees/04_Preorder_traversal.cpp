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

void preOrder(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}

int main(){
    Node* root = preorderInsertion();
    preOrder(root);
    return 0;
}