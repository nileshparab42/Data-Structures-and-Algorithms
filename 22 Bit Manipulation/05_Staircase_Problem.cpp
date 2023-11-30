#include<iostream>
using namespace std;

int stairCase(int n){
    int count=0;
    while(n){
        n=n&(n-1);
        count++;
    }
    return count;
}

int main(){
    cout<<stairCase(14);
    return 0;
}