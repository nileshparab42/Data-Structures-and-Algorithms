#include<iostream>
#include<vector>
using namespace std;

int clearLast(int num,int l){
    int m=-1;
    m=m<<l;
    num=num&m;
    return num;
}

int main(){
    cout<<clearLast(7,1);
    return 0;
}