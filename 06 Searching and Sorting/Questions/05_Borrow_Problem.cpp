#include<iostream>
#include<vector>
using namespace std;

bool ifsq(int n){
    int s=0;
    int e=n;
    int mid;
    while(s<=e){
        mid=s+(e-s)/2;
        if((mid*mid)==n){
            return true;
        }
        else if((mid*mid)>n){
            e=mid-1;
        }
        else if((mid*mid)<n){
            s=mid+1;
        }
    }
    return false;
}

int borrow(int n){
    int count=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int m=i*j;
            if(ifsq(m)){
                cout<<i<<"and"<<j<<"\n";
                count++;
            }
        }
    }
    return count;
}

int main(){
    cout<<"\nAns:"<<borrow(5);
    return 0;
}