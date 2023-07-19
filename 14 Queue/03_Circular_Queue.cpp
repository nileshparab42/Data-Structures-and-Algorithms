#include<iostream>
using namespace std;

class  cqueue{

    int* arr;
    int size;
    int front;
    int rare;

    
    public:

    cqueue(int size){
        this->size=size;
        arr = new int[size];
        front=-1;
        rare=-1;
    }

    void push(int data){
        cout<<"Front:"<<front<<"\n";
        cout<<"Rare:"<<rare<<"\n";
        //Queue is Full
        if((front==0&&rare==size-1)||(rare==front-1)){
            cout<<"Queue is Full"<<"\n";
            return;
        }
        //First Element
        else if(front==-1){
            front=0;
            rare=0;
            arr[rare]=data;

        }
        //Circular nature
        else if((rare==size-1)&&(front!=0)){
            rare=0;
            arr[rare]=data;
        }
        //Default
        else{
            rare++;
            arr[rare]=data;
        }
        cout<<"\n";

    }
    void pop(){
        //Queue is Empty
        if((front==-1)&&(rare==-1)){
            cout<<"Queue is Empty";
            return;
        }
        //Last Element
        else if(front==rare){
            arr[front]=-1;
            front=-1;
            rare=-1;
        }
        //Circular nature
        else if(front==size-1){
            arr[front]=-1;
            front=0;
        }
        //Default
        else{
            arr[front]=-1;
            front++;
        }

    }
    void print(){
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
    }

};



int main(){
    cqueue cq(5);
    cq.push(10);
    cq.push(20);
    cq.push(30);
    cq.push(40);
    cq.push(50);
    
    cq.pop();
    cq.pop();

    cq.push(60);
    cq.push(70);
    cq.pop();
    cq.pop();
    cq.pop();
    cq.pop();
    cq.pop();
    cq.pop();

    cq.print();
    return 0;
}