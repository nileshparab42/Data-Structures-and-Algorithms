#include<iostream>
#include<vector>
using namespace std;

bool issafe(int i,int j,int row,int col,int m[][4],bool visited[][4]){
 if((i>=0 && i<col && j>=0 && j<row) && (visited[i][j]==0) && (m[i][j]==1)){
    return true;
 }
 return false;
}

void solveMaze(int m[][4],int& row,int& col,int i,int j,bool visited[][4], vector<string>& path,string output){
    if(i==row-1 && j==col-1){
        path.push_back(output);
        return;
    }
    //left i,j-1
    if(issafe(i,j-1,row,col,m,visited)){
        visited[i][j-1]=1;
        solveMaze(m,row,col,i,j-1,visited,path,output+"L");
        visited[i][j-1]=0;
    }
    //right i,j+1
    if(issafe(i,j+1,row,col,m,visited)){
        visited[i][j+1]=1;
        solveMaze(m,row,col,i,j+1,visited,path,output+"R");
        visited[i][j+1]=0;
    }
    //up i-1,j
    if(issafe(i-1,j,row,col,m,visited)){
        visited[i-1][j]=1;
        solveMaze(m,row,col,i-1,j,visited,path,output+"U");
        visited[i-1][j]=0;
    }
    //down i+1,j
    if(issafe(i+1,j,row,col,m,visited)){
        visited[i+1][j]=1;
        solveMaze(m,row,col,i+1,j,visited,path,output+"D");
        visited[i+1][j]=0;
    }
}

main(){
    int m[4][4]={{1,0,0,0},{1,1,0,0},{1,1,0,0},{0,1,1,1}};
    int row=4;
    int col=4;
    bool visited[4][4]={{1,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
    vector<string> path;
    string output="";
    solveMaze(m,row,col,0,0,visited,path,output);
    for(auto i:path){
        cout<<i<<" ";
    }
}
