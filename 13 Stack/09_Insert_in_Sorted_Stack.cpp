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

int main(){
    stack<int> s;
    s.push(50);
    s.push(40);
    s.push(30);
    s.push(20);
    s.push(10);

    int ele=45;

    insertInSorted(s,ele);

    while(!s.empty()){
        cout<<s.top()<<"\n";
        s.pop();
    }
    return 0;
}