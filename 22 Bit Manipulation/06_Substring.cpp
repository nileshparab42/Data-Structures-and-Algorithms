#include<iostream>
#include<vector>
using namespace std;

void subStr(string s){
    vector<string> ans;
    int len=s.length();
    for(int i=0;i<(1<<len);i++){
        string n="";
        for(int j=0;j<len;j++){
            if(i&(1<<j)){
                n=n+s[j];
            }
        }
        cout<<n<<"\n";
    }
}

int main(){
    subStr("abc");
    return 0;
}