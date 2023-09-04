#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<queue>
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
    void DFS(int src,unordered_map<int,bool>& visited2){
        visited2[src]=true;
        cout<<src<<" ";
        for(auto i:adj[src]){
            if(visited2[i]!=true){
                DFS(i,visited2);
            }
        }
    }

};



int main(){
    graph g;
    g.addNode(0,1,0);
    g.addNode(1,3,0);
    g.addNode(1,4,0);
    g.addNode(0,2,0);
    g.addNode(2,5,0);
    g.addNode(2,6,0);
    unordered_map<int,bool> visited;
    for(int i=0;i<7;i++){
        if(visited[i]!=true){
            g.BFS(i,visited);
        }
    }
    cout<<endl;
    unordered_map<int,bool> visited2;
    for(int i=0;i<7;i++){
        if(visited2[i]!=true){
            g.DFS(i,visited2);
        }
    }
    return 0;
}