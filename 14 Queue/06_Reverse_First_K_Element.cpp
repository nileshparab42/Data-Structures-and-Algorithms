#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void reverseFirstK(queue<int>& q,int k){
    int n=q.size();
    stack<int> st;
    if(q.empty()){
        return;
    }
    if(n<k || k<=0){
        return;
    }
    for(int i=0;i<k;i++){
        int temp=q.front();
        q.pop();
        st.push(temp);
    }
    while(!st.empty()){
        int temp=st.top();
        q.push(temp);
        st.pop();
    }
    for(int i=0;i<n-k;i++){
        int temp=q.front();
        q.pop();
        q.push(temp);
    }

}

int main(){
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    int k=2;
    reverseFirstK(q,k);
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}