#include<iostream>
#include<vector>
using namespace std;

void printBoard(int& n, vector<vector<char>>& board){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
}

bool isSafe(int row,int col,vector<vector<char>>& board,int& n){
    int i=row;
    int j=col;
    while(j>=0){
        if(board[i][j]=='Q'){
            return false;
        }
        j--;
    }
    i=row;
    j=col;
    while(j>=0 && i>=0){
        if(board[i][j]=='Q'){
            return false;
        }
        i--;
        j--;
    }
    i=row;
    j=col;
    while(j>=0 && i<n){
        if(board[i][j]=='Q'){
            return false;
        }
        i++;
        j--;
    }
    return true;
}


void solve(vector<vector<char>>& board,int& n,int col){
    //base condition
    if(col>=n){
        printBoard(n,board);
        return;
    }
    //solve 1 case
    for(int row=0;row<n;row++){
        if(isSafe(row,col,board,n)){
            board[row][col]='Q';
            solve(board,n,col+1);
            board[row][col]='-';
        }
    }
}

int main(){
    int n=4;
    vector<vector<char>> board(n,vector<char>(n,'-'));
    solve(board,n,0);
    return 0;
}
