#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
int solve(vector<int>& coins, int total){
    if(total==0){
        return 0;
    }
    else if(total<0){
        return INT_MAX;
    }
    int mini=INT_MAX;
    for(int i=0;i<coins.size();i++){
        int ans= solve(coins,total-coins[i]) +1;
        if(ans>0){
            mini=min(ans,mini);
        }
    }
    return mini;
}
int main(){
    int total=11;
    vector<int> coins{1,2,5};
    int mini=INT_MAX;
    int ans = solve(coins,total);
    cout<<ans;
    return 0;
}
