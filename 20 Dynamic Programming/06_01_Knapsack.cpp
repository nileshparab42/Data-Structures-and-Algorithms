#include<iostream>
#include<vector>
using namespace std;

int solveRec(int value[],int weight[],int capacity,int index){
    if(index==0){
        if(weight[0]<=capacity){
            return value[0];
        }
        else{
            return 0;
        }
    }
    int include = 0;
    if(weight[index]<=capacity){
            include = value[index] + solveRec(value,weight,capacity-weight[index],index-1);
    }
    int exclude = 0 + solveRec(value,weight,capacity,index-1);

    return max(include,exclude);
}

int solveMem(int value[],int weight[],int capacity,int index,vector<vector<int>>& dp){
    if(index==0){
        if(weight[0]<=capacity){
            return value[0];
        }
        else{
            return 0;
        }
    }
    if(dp[index][capacity]!=-1){
        return dp[index][capacity];
    }
    int include = 0;
    if(weight[index]<=capacity){
            include = value[index] + solveMem(value,weight,capacity-weight[index],index-1,dp);
    }
    int exclude = 0 + solveMem(value,weight,capacity,index-1,dp);

    dp[index][capacity] = max(include,exclude);
    return dp[index][capacity];
}

int solveTab(int value[],int weight[],int totalcapacity,int n){
    vector<vector<int>> dp(n,vector<int>(totalcapacity+1,0));

    for(int w=weight[0];w<=totalcapacity;w++){
        if(weight[0]<=totalcapacity){
            dp[0][w]=value[0];
        }
        else{
            dp[0][w]=0;
        }
    }
    for(int index=1;index<n;index++){
        for(int capacity=weight[index];capacity<=totalcapacity;capacity++){
            int include = 0;
            if(weight[index]<=capacity){
                    include = value[index] + dp[index-1][capacity-weight[index]];
            }
            int exclude = 0 + dp[index-1][capacity];

            dp[index][capacity] = max(include,exclude);
        }
    }
    return dp[n-1][totalcapacity];
    
}

int solveSO(int value[],int weight[],int totalcapacity,int n){
    vector<int> prev(totalcapacity+1,0);
    vector<int> curr(totalcapacity+1,0);

    for(int w=weight[0];w<=totalcapacity;w++){
        if(weight[0]<=totalcapacity){
            prev[w]=value[0];
        }
        else{
            prev[w]=0;
        }
    }
    for(int index=1;index<n;index++){
        for(int capacity=weight[index];capacity<=totalcapacity;capacity++){
            int include = 0;
            if(weight[index]<=capacity){
                    include = value[index] + prev[capacity-weight[index]];
            }
            int exclude = 0 + prev[capacity];

            curr[capacity] = max(include,exclude);
        }
        prev=curr;
    }
    return prev[totalcapacity];
    
}

int solveSO2(int value[],int weight[],int totalcapacity,int n){
    vector<int> curr(totalcapacity+1,0);

    for(int w=weight[0];w<=totalcapacity;w++){
        if(weight[0]<=totalcapacity){
            curr[w]=value[0];
        }
        else{
            curr[w]=0;
        }
    }
    for(int index=1;index<n;index++){
        for(int capacity=totalcapacity;capacity>=weight[index];capacity--){
            int include = 0;
            if(weight[index]<=capacity){
                    include = value[index] + curr[capacity-weight[index]];
            }
            int exclude = 0 + curr[capacity];

            curr[capacity] = max(include,exclude);
        }
    }
    return curr[totalcapacity];
    
}

int main(){
    int value[4] = {60, 100, 120};
    int weight[4] = {10, 20, 30};
    int capacity = 50;
    int n = 3;

    // vector<vector<int>> dp(n,vector<int>(capacity+1,-1));
    // cout<< solveMem(value,weight,capacity,n-1,dp);
    cout<< solveSO2(value,weight,capacity,n);

    return 0;
}