#include<iostream>
#include<unordered_map>
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

bool isCircular(Node* head){
    unordered_map<Node*,bool> nodes;
    Node* temp=head;
    while (temp!=NULL)
    {
        if(nodes[temp]!=true){
            nodes[temp]=true;
            temp=temp->next;
        }
        else{
            return true;
        }
    }
    return false;
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
    Fourth->next=Fifth;
    Fifth->next=NULL;
    if(isCircular(First)){
        cout<<"Circular";
    }
    else{
        cout<<"Not Circular";
    }
    return 0;
}