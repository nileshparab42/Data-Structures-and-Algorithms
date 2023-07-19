#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(' || s[i]=='{'|| s[i]=='['){
                st.push(s[i]);
            }
            else{
                if(st.empty()){
                    return false;
                }
                else if(s[i]==')' && st.top()=='('){
                    st.pop();
                }
                else if(s[i]=='}' && st.top()=='{'){
                    st.pop();
                }
                else if(s[i]==']' && st.top()=='['){
                    st.pop();
                }
                else{
                    return false;
                }
            }
        }

        if(!st.empty()){
            return false;
        }
        else{
            return true;
        }
    }

int main(){
    string s="({[}})";

    if(isValid(s)){
        cout<<"Valid";
    }
    else{
        cout<<"Not Valid";
    }

    return 0;
}