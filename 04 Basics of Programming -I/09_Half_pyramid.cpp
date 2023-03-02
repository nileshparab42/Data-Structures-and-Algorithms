#include<iostream>
using namespace std;
int main(){
    int count;
    cin>>count;
    for(int i=count; i>0; i--){
        //We can also use count-j if first loop is incremental loops 3
        for(int j=1; j<=i; j++){
            cout<<"* ";
        }
        cout<<endl;
    }
}