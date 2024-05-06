#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void printLL(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}

bool isLoop(Node* head){
    Node* slow=head;
    Node* fast=head;

    while(slow!=NULL && fast!=NULL){
        slow=slow->next;
        fast=fast->next;
        if(fast){
            fast=fast->next;
        }
        if(slow == fast){
            return true;
        }
    }

    return false;
}


int main(){
    Node* node1 = new Node(10);
    Node* node2 = new Node(20);
    Node* node3 = new Node(30);
    node1->next=node2;
    node2->next=node3;
    node3->next=node1;
    Node* temp = node1;
    // printLL(temp);
    cout<<isLoop(temp);
    return 0;
    
}