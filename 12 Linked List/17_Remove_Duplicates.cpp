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
int lenLL(Node* head){
    int length=0;
    Node* temp=head;
    while (temp!=NULL)
    {
        temp=temp->next;
        length++;
    }
    return length;
}

void removedup(Node* head){
    Node* curr=head;
    Node* right=curr->next;
    while(right!=NULL){
        if(right->data==curr->data){
            curr->next=right->next;
            right=right->next;
        }
        else{
            curr=right;
            right=right->next;
        }
    }
}

int main(){
    Node* First=new Node(20);
    Node* Second=new Node(20);
    Node* Third=new Node(30);
    Node* Fourth=new Node(30);
    Node* Fifth=new Node(40);
    Node* Sixth=new Node(40); 
    First->next=Second;
    Second->next=Third;
    Third->next=Fourth;
    Fourth->next=Fifth;
    Fifth->next=Sixth;
    printLL(First);
    cout<<endl;
    removedup(First);
    printLL(First);
    return 0;
}