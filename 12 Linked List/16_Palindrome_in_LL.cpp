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

bool isPalindrome(Node* head){
    Node* ptr1=head;
    Node* mid=middleofLL(ptr1);
    Node* ptr2=reverseLLloop(mid->next);
    while(ptr2!=NULL){
        if(ptr1->data!=ptr2->data){
            return false;
        }
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    return true;
}


int main(){
    Node* First=new Node(10);
    Node* Second=new Node(20);
    Node* Third=new Node(30);
    Node* Fourth=new Node(30);
    Node* Fifth=new Node(20);
    Node* Sixth=new Node(10); 
    First->next=Second;
    Second->next=Third;
    Third->next=Fourth;
    Fourth->next=Fifth;
    Fifth->next=Sixth;
    // printLL(First);
    if(isPalindrome(First)){
        cout<<"String is Palindrome !";
    }else{
        cout<<"String is not Palindrome !";
    }
    return 0;
}