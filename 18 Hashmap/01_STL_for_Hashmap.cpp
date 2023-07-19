#include<iostream>
#include<unordered_map>
#include<map>
using namespace std;
int main(){
    unordered_map<string,int> marks;
    pair<string,int> temp("Askan",7); //first
    pair<string,int> temp2;
    temp2 = make_pair("Nilesh",9);
    marks.insert(temp);
    marks.insert(temp2);
    marks["Riya"]=10;

    cout<<marks.at("Riya")<<"\n";
    cout<<marks["Nilesh"]<<"\n";

    cout<<marks.size()<<"\n";
    return 0;
}