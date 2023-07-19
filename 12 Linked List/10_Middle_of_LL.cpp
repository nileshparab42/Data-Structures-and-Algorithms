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

Node* middleofLL(Node* head){
    Node* slow=head;
    Node* fast=head->next;
    while(fast!=NULL && slow!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
    }
    return slow;
}

int main(){
    Node* First=new Node(10);
    Node* Second=new Node(20);
    Node* Third=new Node(30);
    Node* Fourth=new Node(50);
    Node* Fifth=new Node(70);
    First->next=Second;
    Second->next=Third;
    Third->next=Fourth;
    Fourth->next=NULL;
    printLL(First);
    cout<<"\n";
    Node* mid=middleofLL(First);
    cout<<mid->data;
    return 0;
}