#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool findRedundantBrackets(string &s)
{
    stack<char> st;
    for(int i=0;i<s.length();i++){
        if(s[i]=='(' || s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/'){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            if(st.empty()){
                return true;
            }
            else if(st.top()=='('){
                return true;
            }
            else{
                while(st.top()!='('){
                    st.pop();
                }
                st.pop();
            }
        }
    }
    return false;
}

int main(){
    string s="((b-c+a/c))";

//     5
// (a+(b*(a/c)))
// (a/c+(b))
// (b/a)
// ((b-c+a/c))
// ((b*c)*(a/b))

    if(findRedundantBrackets(s)){
        cout<<"Not Redundant";
    }
    else{
        cout<<"Redundant";
    }

    return 0;
}