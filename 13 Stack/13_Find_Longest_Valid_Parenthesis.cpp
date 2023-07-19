#include<iostream>
#include<stack>
#include<string>
using namespace std;

int longestValidParentheses(string s) {
    stack<int> st;
    st.push(-1);
    int maxLen=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                st.push(i);
            }
            else{
                st.pop();
                if(st.empty()){
                    st.push(i);
                }
                else{
                    int currLen=i-st.top();
                    maxLen=max(maxLen,currLen);
                }
            }
        }
        return maxLen;
    }

int main(){
    string s=")))((()))((())";
    cout<<longestValidParentheses(s);
    return 0;
}