#include<iostream>
#include<queue>
using namespace std;

int main(){

    priority_queue<int> pq; //Max Heap
    priority_queue<int,vector<int>,greater<int>> minheap; //Min Heap
    minheap.push(10);
    minheap.push(30);
    minheap.push(5);
    minheap.push(21);
    minheap.push(17);
    cout<<minheap.top();
    return 0;
}