#include<iostream>
using namespace std;
int main(){
    // Findout ith bit
    int n=11;
    int i=0;
    int num=1;
    num=num<<i;
    cout<<"Bit at ith position is "<<(n&num?1:0);

    // Set ith Bit
    n=10;
    i=2;
    num=1;
    num=num<<i;
    n=n|num;
    cout<<"\nNumber after set is "<<n;

    // Clear ith Bit
    n=10;
    i=1;
    num=1;
    num=num<<i;
    num=~(num);
    n=n&num;
    cout<<"\nNumber after clear is "<<n;

    

    // Update ith Bit
    int u=1;
    n=10;
    i=2;
    num=1;
    num=num<<i;
    num=~(num);
    n=n&num;
    num=u;
    num=num<<i;
    n=n|num;
    cout<<"\nNumber after update is "<<n;





    return 0;
}
