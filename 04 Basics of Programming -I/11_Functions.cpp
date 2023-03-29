#include<iostream>
using namespace std;
int isprime(int a){
    for(int i=2;i<a;i++){
        if(a%i==0){
            return false;
        }
    }
    return true;
}
int main(){
    cout<<isprime(11);
    return 0;

}
