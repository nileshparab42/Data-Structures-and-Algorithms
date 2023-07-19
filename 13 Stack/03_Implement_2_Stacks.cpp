#include<iostream>
using namespace std;

class Stack{
    public:
    int* arr;
    int size;
    int top1;
    int top2;
    Stack(int size){
        this->size=size;
        arr=new int[size];
        top1=-1;
        top2=size;
    }
    void push1(int data){
        if(top2-top1==1){
            cout<<"Stack Overflow"<<endl;
        }
        else{
            top1++;
            arr[top1]=data;
        }
    }
    void push2(int data){
        if(top2-top1==1){
            cout<<"Stack Overflow"<<endl;
        }
        else{
            top2--;
            arr[top2]=data;
        }
    }
    void pop1(){
        if(top1==-1){
            cout<<"stack is Empty"<<endl;
        }
        else{
            arr[top1]=0;
            top1--;
        }
    }
    void pop2(){
        if(top2==size){
            cout<<"stack is Empty"<<endl;
        }
        else{
            arr[top2]=0;
            top2++;
        }
    }
    void print(){
        for(int i=0;i<size;i++){
            cout<<*(arr+i)<<" ";
        }
        cout<<endl;
    }
    
};

int main(){
    Stack s(5);
    s.push1(10);
    s.print();
    s.push2(100);
    s.print();
    s.push2(120);
    s.print();
    s.push1(20);
    s.print();
    s.push1(30);
    s.print();
    s.push2(130);
    s.print();
    s.push1(150);
    s.print();
    s.pop2();
    s.print();
    s.push2(1670);
    s.print();
    return 0;
}