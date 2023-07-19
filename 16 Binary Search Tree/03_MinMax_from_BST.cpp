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



void levelOrderTrans(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* temp=q.front();
        q.pop();
        if(temp!=NULL){
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
        else{
            cout<<"\n";
            if(!q.empty()){
                q.push(NULL);
            }
        }
        
    }
}

Node* insertBST(int data,Node* root){
    if(root==NULL){
        Node* temp=new Node(data);
        return temp;
    }
    if(root->data>data){
        root->left=insertBST(data,root->left);
    }
    else{
        root->right=insertBST(data,root->right);
    }
}

Node* createBST(Node* root,int arr[],int size){
    for(int i=0;i<size;i++){
        int data=arr[i];
        root = insertBST(data,root);
    }
    return root;
}


int minBST(Node* root){
    if(root==NULL){
        return -1;
    }
    if(root->left==NULL){
        return root->data;
    }
    return minBST(root->left);
}

int maxBST(Node* root){
    if(root==NULL){
        return -1;
    }
    else if(root->right==NULL){
        return root->data;
    }
    else{
        return maxBST(root->right);
    }
}

int main(){
    Node* root = NULL;
    int arr[11]={10,20,5,11,17,2,4,8,6,25,15};
    root = createBST(root,arr,11);
    cout<<"Minimum Element : "<<minBST(root)<<"\n";
    cout<<"Maximum Element : "<<maxBST(root)<<"\n";
    return 0;
}