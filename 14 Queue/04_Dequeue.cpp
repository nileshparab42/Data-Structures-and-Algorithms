#include<iostream>
using namespace std;

class  dequque{

    int* arr;
    int size;
    int front;
    int rare;

    
    public:

    dequque(int size){
        this->size=size;
        arr = new int[size];
        front=-1;
        rare=-1;
    }

    void push_back(int data){
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
    void push_front(int data){
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
        else if((front==0)&&(rare!=size-1)){
            front=size-1;
            arr[front]=data;
        }
        //Default
        else{
            front--;
            arr[front]=data;
        }
        cout<<"\n";

    }
    void pop_front(){
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
    void pop_back(){
        //Queue is Empty
        if((front==-1)&&(rare==-1)){
            cout<<"Queue is Empty";
            return;
        }
        //Last Element
        else if(front==rare){
            arr[rare]=-1;
            front=-1;
            rare=-1;
        }
        //Circular nature
        else if(rare==0){
            arr[rare]=-1;
            rare=size-1;
        }
        //Default
        else{
            arr[rare]=-1;
            rare--;
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
    dequque cq(5);
    cq.push_front(10);
    cq.push_front(20);
   cq.push_front(30);
   cq.push_back(40);

   cq.pop_back();
   cq.pop_front();

   cq.pop_back();
   cq.pop_back();

   cq.push_front(42);

    cq.print();
    return 0;
}