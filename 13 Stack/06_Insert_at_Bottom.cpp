#include<iostream>
#include<stack>
using namespace std;

void solve(stack<int>& s,int& ele){
    if(s.size()==0){
        s.push(ele);
        return;
    }
    int temp=s.top();
    s.pop();
    solve(s,ele);
    s.push(temp);
}

void insertAtBottom(stack<int>& s){
    if(s.empty()){
        return;
    }
    int ele=s.top();
    s.pop();
    solve(s,ele);
}

int main(){
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);


    insertAtBottom(s);

    while(!s.empty()){
        cout<<s.top()<<"\n";
        s.pop();
    }
    return 0;
}