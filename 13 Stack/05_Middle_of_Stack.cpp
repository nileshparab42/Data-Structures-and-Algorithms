#include<iostream>
#include<stack>
using namespace std;

void midStack(stack<int> s,int k){
    if(((k/2)+1)==s.size()){
        cout<<s.top();
        return;
    }
    int temp=s.top();
    s.pop();
    midStack(s,k);
    s.push(temp);
}

int main(){
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    s.push(70);
    s.push(80);
    s.push(90);
    s.push(100);
    midStack(s,10);
    
    return 0;
}