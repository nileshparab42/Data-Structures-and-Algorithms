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

int main(){
    Node* root = preorderInsertion();
    levelOrderTrans(root);
    return 0;
}