#include<iostream>
using namespace std;

class heap{
    public:
    int* arr;
    int size;
    int len;
    heap(){

    }
    heap(int size){
        this->size=size;
        arr = new int[size];
        len=0;
    }
    void printheap(){
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
    }
    void insert(int data){
        len++;
        arr[len]=data;

        int index=len;
        int parentindex=index/2;

        while(index>0){
            parentindex=index/2;
            if(arr[parentindex]<arr[index]){
                swap(arr[parentindex],arr[index]);
                index=parentindex;
            }
            else{
                break;
            }
        }
    }
};


int main(){
    heap h(20);
    cout<<h.size;
    h.insert(100);
    h.insert(50);
    h.insert(60);
    h.insert(30);
    h.insert(40);
    h.insert(45);
    h.insert(55);
    h.insert(10);
    h.insert(22);
    h.insert(57);
    h.insert(102);
    h.printheap();
    return 0;
}