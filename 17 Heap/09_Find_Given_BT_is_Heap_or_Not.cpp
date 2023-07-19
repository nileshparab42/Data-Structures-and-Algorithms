#include<iostream>
#include<limits.h>
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

bool btorNot(Node* root,int parval){
    if(root==NULL){
        return true;
    }
    bool leftans = btorNot(root->left,root->data);
    bool rightans = btorNot(root->right,root->data);
    if(leftans && rightans && root->data<parval){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    Node* root = preorderInsertion();
    cout<<"\n Ans: "<<btorNot(root,INT_MAX);
    return 0;
}