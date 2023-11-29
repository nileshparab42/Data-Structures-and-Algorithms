#include<iostream>
using namespace std;

int clearInRange(int n,int i,int j){
    int m=-1;
    int a=~(m<<j);
    int b=-1<<(i+1);
    m=a|b;
    n=n&m;
    return n;
}

int main(){
    cout<<clearInRange(11,2,1);
    return 0;
}