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



int main(){
    Node* root = NULL;
    int arr[5]={10,23,8,25,11};
    root = createBST(root,arr,5);
    levelOrderTrans(root);
    return 0;
}