#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<queue>
#include<algorithm>
#include<stack>
using namespace std;

class graph{
    public:
    unordered_map<int,list<int>> adj;

    void addNode(int u,int v,int type){
        // type 0 -> Undirected
        // type 1 -> Directed
        adj[u].push_back(v);
        if(type==0){
            adj[v].push_back(u);
        }
    } 

    void printGraph(){
        for(auto node:adj){
            cout<<node.first<<": ";
            for(auto neb:node.second){
                cout<<"("<<neb<<")";
            }
            cout<<endl;

        }
    }



    void BFS(int src,unordered_map<int,bool>& visited){
    queue<int> q;
    q.push(src);
    visited[src]=true;
    while(!q.empty()){
        int node=q.front();
        cout<<node<<" ";
        q.pop();
        for(auto i:adj[node]){
                if(visited[i]!=true){
                    q.push(i);
                    visited[i]=true;
                }
            }
        }
    }

    bool cycleDetBFS(int src,unordered_map<int,bool>& visited){
    unordered_map<int,int> par;
    queue<int> q;
    q.push(src);
    par[src]=-1;
    visited[src]=true;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        for(auto neb:adj[node]){
                if(visited[neb]!=true){
                    q.push(neb);
                    visited[neb]=true;
                    par[neb]=node;
                }
                else{
                    if(par[node]!=neb){
                        return true;
                    }
                }
            }
        }
        return false;
    }

    void DFS(int src,unordered_map<int,bool>& visited2){
        visited2[src]=true;
        cout<<src<<" ";
        for(auto i:adj[src]){
            if(visited2[i]!=true){
                DFS(i,visited2);
            }
        }
    }

    bool UndirectedCycleDetDFS(int src,unordered_map<int,bool>& visited2,int parent){
        visited2[src]=true;
        for(auto neb:adj[src]){
            if(visited2[neb]!=true){
                bool ans = UndirectedCycleDetDFS(neb,visited2,src);
                if(ans==true){
                    return true;
                }
            }
            else{
                if(neb != parent){
                    return true;
                }
            }
        }
        return false;
    }

    bool DirectedCycleDetDFS(int src,unordered_map<int,bool>& visited2,unordered_map<int,bool>& dfsvisited){
        visited2[src]=true;
        dfsvisited[src]=true;
        for(auto neb:adj[src]){
            if(visited2[neb]!=true){
                bool ans = DirectedCycleDetDFS(neb,visited2,dfsvisited);
                if(ans==true){
                    return true;
                }
            }
            else{
                if(dfsvisited[neb]==true){
                    return true;
                }
            }
        }
        dfsvisited[src]=false;
        return false;
    }

    void topoDFS(int src,unordered_map<int,bool>& visited,stack<int>& st){
        visited[src]=true;
        cout<<src<<" ";
        for(auto i:adj[src]){
            if(visited[i]!=true){
                topoDFS(i,visited,st);
            }
        }
        st.push(src);
    }


    void topoBFS(int n,vector<int>& ans){
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

        // for(auto i:indegree){
        //     cout<<i.first<<" "<<i.second<<"\n";
        //     if(i.second==0){
        //         q.push(i.first);
        //     }
        // }

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
    }    


    void shptBFS(int s,int d){
        vector<int> ans;
        queue<int> q;
        unordered_map<int,bool> visited;
        unordered_map<int,int> parent;

        q.push(s);
        visited[s]=true;
        parent[s]=-1;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto neb:adj[node]){
                if(!visited[neb]){
                    q.push(neb);
                    visited[neb]=true;
                    parent[neb]=node;
                }
            }
        }

        int node=d;
        while(node!=-1){
            ans.push_back(node);
            node=parent[node];
        }

        reverse(ans.begin(),ans.end());
        cout<<"\nShortest Path "<<s<<" to "<<d<<": ";
        
        for(auto i:ans){
            cout<<i<<" ";
        }
    }
};





int main(){
    graph g;
    g.addNode(0,1,1);
    g.addNode(0,6,1);
    g.addNode(0,5,1);
    g.addNode(1,2,1);
    g.addNode(2,3,1);
    g.addNode(6,3,1);
    g.addNode(5,4,1);
    g.addNode(4,3,1);
    g.printGraph();

    g.shptBFS(0,3);
   

    return 0;
}