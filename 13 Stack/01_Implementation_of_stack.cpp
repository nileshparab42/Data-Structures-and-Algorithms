#include<iostream>
using namespace std;

class Stack{
    public:
    int* arr;
    int size;
    int top;
    Stack(int size){
        this->size=size;
        arr=new int[size];
        top=-1;
    }
    void push(int data){
        if(size-top==1){
            cout<<"Stack Overflow"<<endl;
        }
        else{
            top++;
            arr[top]=data;
        }
    }
    void pop(){
        if(top==-1){
            cout<<"stack is Empty"<<endl;
        }
        else{
            top--;
        }
    }
    void topEle(){
        if(top==-1){
            cout<<"stack is Empty"<<endl;
        }
        else{
            cout<<"Top is "<<arr[top]<<endl;
        }
    }
    bool isEmpty(){
        if(top==-1){
            return true;
        }
        else{
            return false;
        }
    }
    int stSize(){
        return top+1;
    }
};

int main(){
    Stack s(5);
    cout<<s.isEmpty();
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.topEle();
    cout<<s.stSize()<<endl;
    s.pop();
    s.topEle();
    cout<<s.stSize()<<endl;
    cout<<s.isEmpty();
    return 0;
}