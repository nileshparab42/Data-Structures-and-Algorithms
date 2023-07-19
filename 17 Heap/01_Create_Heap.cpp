#include<iostream>
using namespace std;

class heap{
    public:
    int* arr;
    int size;
    heap(){

    }
    heap(int size){
        this->size=size;
        arr = new int[size];
    }

};


int main(){
    heap h(10);
    cout<<h.size;
    return 0;
}