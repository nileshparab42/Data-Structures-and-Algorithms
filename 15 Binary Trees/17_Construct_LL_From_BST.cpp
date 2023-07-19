
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

Node* constructInorder(int inorder[], int s, int e){
    if(s>e){
        return NULL;
    }
    int mid=(s+e)/2;
    Node* ele=new Node(inorder[mid]);
    ele->left=constructInorder(inorder,s,mid-1);
    ele->right=constructInorder(inorder,mid+1,e);
    return ele;
}

Node* constructLL(Node* root,Node*& head){
    if(root==NULL){
        return NULL;
    }
    constructLL(root->right,head);
    root->right=head;
    if(head!=NULL){
        head->left=root;
    }
    head=root;
    constructLL(root->left,head);
    return head;
}

Node* constructBST(Node*& head,int n){
    if(n<=0 || head==NULL){
        return NULL;
    }
    Node* leftsubtree = constructBST(head,n/2);
    Node* root = head; 
    root->left = leftsubtree;
    head=head->right;
    root->right = constructBST(head,n-1-(n/2));
    return root;
}

int main(){
    int inorder[9]={1,2,3,4,5,6,7,8,9};
    Node* root=NULL;
    int s=0,e=8;
    root = constructInorder(inorder,s,e);
    levelOrderTrans(root);

    Node* head=NULL;
    head = constructLL(root,head);

    cout<<"Linked List : \n";
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->right;
    }

    Node* bsthead = constructBST(head,9);
    cout<<"\nTree: \n";
    levelOrderTrans(bsthead);



    return 0;
}