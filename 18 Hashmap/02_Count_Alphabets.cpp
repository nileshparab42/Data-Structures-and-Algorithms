#include<iostream>
#include<unordered_map>
#include<map>
using namespace std;

void countAlpha(string& name){
    map<char,int> alphabets;
    for(int i=0;i<name.size();i++){
        alphabets[name[i]]++;
    }
    for(auto i:alphabets){
        cout<<i.first<<"="<<i.second<<"\n";
    }
}

int main(){
    string name="ASKAAN";
    countAlpha(name);
    return 0;
}