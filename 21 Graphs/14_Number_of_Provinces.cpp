class Solution {
public:
    void dfs(int src,unordered_map<int,bool>& visited,vector<vector<int>>& isConnected){
        visited[src]=true;
        for(int i=0;i<isConnected[src].size();i++){
            if(!visited[i] && src!=i && isConnected[src][i]==1){
                dfs(i,visited,isConnected);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int,bool> visited;
        int count=0;
        for(int i=0;i<isConnected.size();i++){
            if(!visited[i]){
                dfs(i,visited,isConnected);
                count++;
            }
        }
        return count;
    }
};