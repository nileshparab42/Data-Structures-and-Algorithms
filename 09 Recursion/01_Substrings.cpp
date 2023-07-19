#include<iostream>
using namespace std;
void solve(string& s,int i,string ans){
    if(i>=s.length()){
        cout<<ans<<" ";
        return;
    }
    solve(s,i+1,ans);
    ans.push_back(s[i]);
    solve(s,i+1,ans);
}
int main(){
    string s="abc";
    int i=0;
    string ans="";
    solve(s,i,ans);
    return 0;
}
