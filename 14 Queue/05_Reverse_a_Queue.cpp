#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void reverseQueue(queue<int>& q){
    stack<int> st;
    while(!q.empty()){
        int temp = q.front();
        st.push(temp);
        q.pop();
    }
    while(!st.empty()){
        int temp = st.top();
        q.push(temp);
        st.pop();
    }
}

void reverseQueueRec(queue<int>& q){
    //Base Case
    if(q.empty()){
        return;
    }
    int temp = q.front();
    q.pop();
    reverseQueueRec(q);
    q.push(temp);
}

int main(){
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    // reverseQueue(q);
    reverseQueueRec(q);
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}