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

    bool cycleDetDFS(int src,unordered_map<int,bool>& visited2,int parent){
        visited2[src]=true;
        for(auto neb:adj[src]){
            if(visited2[neb]!=true){
                bool ans = cycleDetDFS(neb,visited2,src);
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

};



int main(){
    graph g;
    g.addNode(0,1,0);
    g.addNode(1,2,0);
    g.addNode(2,3,0);
    g.addNode(3,4,0);
    // g.addNode(4,2,0);
    unordered_map<int,bool> visited;
    bool ans=false;
    for(int i=0;i<7;i++){
        if(visited[i]!=true){
            ans = g.cycleDetDFS(i,visited,-1);
            if(ans==true){
                break;
            }
        }
    }
    cout<<"\n";
    if(ans==true){
        cout<<"Cycle is Present";
    }
    else{
        cout<<"Cycle is not Present";
    }

    return 0;
}