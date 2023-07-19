#include<iostream>
using namespace std;

class Queue{
    public:
    int* arr;
    int size;
    int front;
    int rare;

    Queue(int size){
        this->size=size;
        arr = new int[size];
        front=0;
        rare=0;
    }

    void push(int data){
        if(rare==size){
            cout<<"Queue is Full";
        }
        else{
            arr[rare]=data;
            rare++;
        }
    }
    void pop(){
        if(front==rare){
            cout<<"Queue is empty";
        }
        else{
            arr[front]=-1;
            front++;
            if(front==rare){
                front=0;
                rare=0;
            }
        }
    }

    int getFront(){
        if(front==rare){
            cout<<"Queue is Empty";
            return -1;
        }
        else{
            return arr[front];
        }
    }
    bool isEmpty(){
        if(front==rare){
            return true;
        }
        else{
            return false;
        }
    }
    int getSize(){
        return rare-front;
    }

};


int main(){
    Queue q(5);
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);

    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();

    q.push(142);
    q.push(143);
    q.push(144);
    q.push(145);
    q.push(146);

    cout<<q.getSize()<<"\n";


    while(!q.isEmpty()){
        cout<<q.getFront()<<" ";
        q.pop();
    }   
    return 0;
}