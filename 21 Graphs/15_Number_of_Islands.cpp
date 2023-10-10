class Solution {
private:
    void bfs(vector<vector<char>>& grid, int row,int col, map<pair<int,int>,bool>& visited){
        queue<pair<int,int>> q;
        q.push({row,col});
        visited[{row,col}]=true;
        while(!q.empty()){
            pair<int,int> node = q.front();
            q.pop();
            int x = node.first;
            int y = node.second;
            int dx[] = {-1,0,1,0};
            int dy[] = {0,1,0,-1};
            for(int i=0;i<4;i++){
                int newX = x+dx[i];
                int newY = y+dy[i];
                if(visited[{newX,newY}]!=true && newX>=0 && newX<grid.size() && newY>=0 && newY<grid[0].size() && grid[newX][newY]=='1'){
                // if(grid[newX][newY]=='1' && visited[{newX,newY}]!=true && newX>=0 && newX<grid.size() && newY>=0 && newY<grid[0].size()){
                    q.push({newX,newY});
                    visited[{newX,newY}]=true;
                }
            }  
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        map<pair<int,int>,bool> visited;
        int count=0;
        for(int row=0;row<grid.size();row++){
            for(int col=0;col<grid[row].size();col++){
                if(visited[{row,col}]!=true && grid[row][col]=='1'){
                    bfs(grid,row,col,visited);
                    count++;
                }
            }
        }
        return count;
    }
};