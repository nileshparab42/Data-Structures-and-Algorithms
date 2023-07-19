#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;
    Node(){
        this->data=0;
        this->prev=NULL;
        this->next=NULL;
    } 
    Node(int data){
        this->data=data;
        this->prev=NULL;
        this->next=NULL;
    }
    ~Node(){

    } 
};

void printDLL(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

void revPrintDLL(Node* tail){
    Node* temp=tail;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->prev;
    }
}

int main(){
    Node* First=new Node(10);
    Node* Second=new Node(20);
    Node* Third=new Node(30);
    Node* Fourth=new Node(50);
    First->next=Second;
    Second->next=Third;
    Third->next=Fourth;
    Second->prev=First;
    Third->prev=Second;
    Fourth->prev=Third;
    printDLL(First);
    cout<<endl;
    revPrintDLL(Fourth);
    return 0;
}