#include<iostream>
#include<stack>
#include<string>
using namespace std;

void revString(string str){
    stack<char> st;
    for(int i=0;i<str.length();i++){
        st.push(str[i]);
    } 
    while(!st.empty()){
        cout<<st.top();
        st.pop();
    }
}

int main(){
    string str="nilesh";
    revString(str);
    return 0;
}