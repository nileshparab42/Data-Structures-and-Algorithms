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

void insertAtHead(int data,Node*& head,Node*& tail){
    if(head==NULL){
        Node* temp=new Node(data);
        head=temp;
        tail=temp;
        return;
    }
    Node* temp=new Node(data);
    temp->next=head;
    head=temp;
}

void insertAtTail(int data,Node*& head,Node*& tail){
    if(head==NULL){
        Node* temp=new Node(data);
        head=temp;
        tail=temp;
        return;
    }
    Node* temp=new Node(data);
    tail->next=temp;
    tail=temp;
}

void insertAtPosition(int data,int position,Node*& head,Node*& tail){
    if(head==NULL){
        Node* temp=new Node(data);
        head=temp;
        tail=temp;
        return;
    }
    if(position<=1){
        insertAtHead(data,head,tail);
        return;
    }
    int length=lenLL(head);
    if(position>length){
        insertAtTail(data,head,tail);
        return;
    }

    //Insert at Middle
    Node* prev=head;
    int step=2;
    while (step<position)
    {
        prev=prev->next;
        step++;
    }
    Node* temp=new Node(data);
    temp->next=prev->next;
    prev->next=temp;
}

int main(){
    Node* head=NULL;
    Node* tail=NULL;
    insertAtHead(10,head,tail);
    insertAtHead(20,head,tail);
    insertAtHead(30,head,tail);
    insertAtHead(40,head,tail);
    insertAtTail(90,head,tail);
    insertAtPosition(42,0,head,tail);
    printLL(head);
    return 0;
}