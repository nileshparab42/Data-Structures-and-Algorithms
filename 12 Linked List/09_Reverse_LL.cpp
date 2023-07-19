#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(){
        this->data=0;
        this->next=NULL;
    }
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
    ~Node(){
        cout<<"Element Deleted";
    }
};

void printLL(Node* head){
    Node* temp=head;
    while (temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}


Node* reverseLLrec(Node* left, Node* curr){
    if(curr==NULL){
        return left;
    }
    Node* right=curr->next;
    curr->next=left;
    left=curr;
    curr=right;
    return reverseLLrec(left,curr);
}

Node* reverseLLloop(Node* head){
    Node* left=NULL;
    Node* curr=head;
    
    while(curr!=NULL){
        Node* right=curr->next;
        curr->next=left;
        left=curr;
        curr=right;
    }
    return left;
}


int main(){
    Node* First=new Node(10);
    Node* Second=new Node(44);
    Node* Third=new Node(32);
    Node* Fourth=new Node(54);
    First->next=Second;
    Second->next=Third;
    Third->next=Fourth;
    printLL(First);
    Node* left=NULL;
    Node* curr=First;
    // Node* head = reverseLLrec(left,curr);
    Node* head = reverseLLloop(First);
    cout<<endl;
    printLL(head);
    return 0;
}