#include<iostream>
#include<stack>
using namespace std;

void insertInSorted(stack<int>& s,int& ele){
    if(s.empty()){
        s.push(ele);
        return;
    }
    else if(ele>s.top()){
        int temp=s.top();
        s.pop();
        insertInSorted(s,ele);
        s.push(temp);
    }
    else{
        s.push(ele);
        return;
    }
}


void sortStack(stack<int>& s){
    if(s.empty()){
        return;
    }
    int temp=s.top();
    s.pop();

    sortStack(s);

    insertInSorted(s,temp);
}


int main(){
    stack<int> s;
    s.push(50);
    s.push(65);
    s.push(10);
    s.push(70);
    s.push(23);


    sortStack(s);

    while(!s.empty()){
        cout<<s.top()<<"\n";
        s.pop();
    }
    return 0;
}