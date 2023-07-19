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


Node* revKEle(Node* head,int& k){
    // cout<<head->data<<"---";
    if(head==NULL){
        return NULL;
    }
    int length=lenLL(head);
    if(length<k){
        return head;
    }
    int count=0;
    Node* left=NULL;
    Node* curr=head; //120 //150
    while(count<k ){
        Node* right=curr->next;
        curr->next=left;
        left=curr;
        curr=right;
        count++;
    }
    // if(curr!=NULL){
    //     head->next=revKEle(curr,k);
    // }
    head->next=revKEle(curr,k);
    return left;

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
    Tenth->next=NULL;
    int k=2;
    Node* ptr = revKEle(First,k);
    printLL(ptr);
    if(ptr==NULL){
        cout<<"yes";
    }

    return 0;
}