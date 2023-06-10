#include<iostream>
#include<vector>  // import header file
using namespace std;
int main(){
    vector<int> arr(10,48);  // type 1 
    vector<int> brr{10,30,20};  // type 2
    
    //insert element
    brr.push_back(40);

    //pop element
    brr.pop_back();

    //size
    cout<<brr.size()<<" ";

    //capacity
    cout<<brr.capacity()<<" ";

    //is empty
    cout<<brr.empty()<<" ";  //0->false 1->true

    //printing vector
    for(auto i:brr){
        cout<<i<<" ";
    }
    
    return 0;
}