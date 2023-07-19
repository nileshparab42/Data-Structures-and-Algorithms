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
        cout<<"Element Deleted"<<" ";
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

void deleteLL(int position,Node*& head,Node*& tail){
    int length=lenLL(head);
    if(head==NULL){
        cout<<"Error: LL is Empty";
        return;
    }
    if(tail==head && position==1){
        Node* temp=head;
        head=NULL;
        tail=NULL;
        delete temp;
        return;
    }
    if(tail==head && position!=1){
        cout<<"Invalid Position";
        return;
    }
    if(position<=0 || position>length){
        cout<<"Invalid Position"<<" ";
        return;
    }   
    if(position==1){
        Node* temp=head;
        head=temp->next;
        temp->next=NULL;
        delete temp;
        return;
    }
    if(position==length){
        Node* temp=head;
        int step=2;
        while(step<length){
            temp=temp->next;
            step++;
        }
        tail=temp;
        Node* ele=temp->next;
        temp->next=NULL;
        ele->next=NULL;
        delete ele;
        return;
    }
    Node* prev=head;
    int step=2;
    while(step<position){
    prev=prev->next;
    step++;
    }
    Node* curr=prev->next;
    prev->next=curr->next;
    curr->next=NULL;
    delete curr;

}

int main(){
    Node* head=new Node(10);
    Node* Second=new Node(20);
    Node* Third=new Node(30);
    Node* tail=new Node(50);
    head->next=Second;
    Second->next=Third;
    Third->next=tail;
    printLL(head);
    // Node* head=NULL;
    // Node* tail=NULL;
    deleteLL(2,head,tail);
    printLL(head);
    cout<<"\nLength:"<<lenLL(head);
    return 0;
}