#include<iostream>
#include<queue>
#include<vector>
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

void inorder(Node* root,vector<int>& arr){
    if(root==NULL){
        return;
    }
    inorder(root->left,arr);
    arr.push_back(root->data);
    inorder(root->right,arr);
}

Node* postorder(Node* root,int& i,vector<int>& arr){
    if(root==NULL){
        return NULL;
    }
    root->left = postorder(root->left,i,arr);
    root->right = postorder(root->right,i,arr);
    root->data=arr[i];
    i++;
    return root;
}

Node* convertBSTtoHeap(Node* root){
    vector<int> arr;
    inorder(root,arr);
    int i=0;
    return postorder(root,i,arr);
}


int main(){
    Node* root = NULL;
    int arr[7]={67,10,45,78,56,12,34};
    root = createBST(root,arr,7);
    levelOrderTrans(root);
    cout<<"\n";
    root = convertBSTtoHeap(root);
    levelOrderTrans(root);
    return 0;
}