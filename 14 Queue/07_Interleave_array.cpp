#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void interleave(queue<int>& q){
    int size=q.size();
    int mid=(size/2);
    queue<int> q2;
    for(int i=0;i<mid;i++){
        int temp=q.front();
        q.pop();
        q2.push(temp);
        // cout<<temp<<"\n";
    }
    while(!q2.empty()){
        int ele1=q2.front();
        q2.pop();
        int ele2=q.front();
        q.pop();
        q.push(ele1);
        q.push(ele2);
    }
    if(size&1){
        int ele1=q.front();
        q.pop();
        q.push(ele1);
    }
}

int main(){
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    q.push(70);
    q.push(80);
    q.push(90);
    // q.push(100);
    int k=2;
    interleave(q);
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}