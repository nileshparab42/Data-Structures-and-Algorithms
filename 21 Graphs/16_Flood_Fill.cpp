class Solution {
private:
    void dfs(vector<vector<int>>& ans,map<pair<int,int>,bool>& visited, int sr, int sc, int oldColor,int newColor){
        visited[{sr,sc}]=true;
        ans[sr][sc]=newColor;
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int newX=sr+dx[i];
            int newY=sc+dy[i];
            if(newX>=0 && newY>=0 && newX<ans.size() && newY<ans[newX].size() && visited[{newX,newY}]!=true && ans[newX][newY]==oldColor){
                dfs(ans,visited,newX,newY,oldColor,newColor);
            }
        }
    }
    
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        map<pair<int,int>,bool> visited;
        vector<vector<int>> ans = image;
        int oldColor = image[sr][sc];
        dfs(ans,visited,sr,sc,oldColor,color);
        return ans;
    }
};