#include<iostream>
#include<stack>
#include<string>
#include<vector>
using namespace std;


class MinStack {
public:
    vector<pair<int,int> > st;
    MinStack() {
        
    }
    
    void push(int val) {
        if(st.empty()){
            pair<int,int> p;
            p.first=val;
            p.second=val;
            st.push_back(p);
        }
        else{
            pair<int,int> p;
            p.first=val;
            p.second=min(val,st[st.size()-1].second);
            st.push_back(p);
        }
    }
    
    void pop() {
        st.pop_back();
    }
    
    int top() {
        return st[st.size()-1].first;
    }
    
    int getMin() {
        return st[st.size()-1].second;
    }
};

int main(){
    return 0;
}