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

void removeLoop(Node*& head){
    if(head==NULL){
        return;
    }
    if(head->next==NULL){
        return;
    }
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
            slow=slow->next;
        }
        if(slow==fast){
            slow=head;
            break;
        }
    }
    Node* prev=NULL;

    while(slow!=fast){
        prev=fast;
        fast=fast->next;
        slow=slow->next;
    }
    prev->next=NULL;
    return;
}


int main(){
    Node* First=new Node(10);
    Node* Second=new Node(20);
    Node* Third=new Node(30);
    Node* Fourth=new Node(50);
    Node* Fifth=new Node(70);
    Node* Sixth=new Node(80); //starting point of loop
    Node* Seventh=new Node(90);
    Node* Eighth=new Node(100);
    Node* Nineth=new Node(120);
    Node* Tenth=new Node(150);
    First->next=Second;
    Second->next=Third;
    Third->next=Fourth;
    Fourth->next=Fifth;
    Fifth->next=Sixth;
    Sixth->next=Seventh;
    Seventh->next=Eighth;
    Eighth->next=Nineth;
    Nineth->next=Tenth;
    Tenth->next=Sixth;


    removeLoop(First);
    printLL(First);

    return 0;
}