#include<iostream>
#include<vector>
using namespace std;
int main(){
    int a=10;
    cout<<&a<<endl;  //address of location where a is stored
    int* ptr=&a;
    cout<<ptr<<endl;
    cout<<&ptr<<endl;

    return 0;
}