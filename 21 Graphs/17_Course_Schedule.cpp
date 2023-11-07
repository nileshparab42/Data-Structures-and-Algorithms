class Solution {

private:
bool topoBFS(int n,unordered_map<int,list<int>>& adj){
    vector<int> ans;
    unordered_map<int,int> indegree;
        for(auto node:adj){
            for(auto neb:adj[node.first]){
                indegree[neb]++;
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for(auto neb:adj[node]){
                indegree[neb]--;
                if(indegree[neb]==0){
                    q.push(neb);
                }
            }
        }

        if(ans.size()==n){
            return true;
        }
        else{
            return false;
        }

    }    
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,list<int>> adj;
        for(auto i:prerequisites){
            int u=i[0];
            int v=i[1];
            adj[v].push_back(u);
        }
        return topoBFS(numCourses,adj);
    }
};