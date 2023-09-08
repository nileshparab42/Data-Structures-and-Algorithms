#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<queue>
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

    
};





int main(){
    graph g;
    g.addNode(0,1,1);
    g.addNode(1,2,1);
    g.addNode(2,3,1);
    g.addNode(3,4,1);
    g.addNode(3,5,1);
    g.addNode(5,6,1);
    g.addNode(4,6,1);
    g.addNode(6,7,1);
    unordered_map<int,bool> visited;
    unordered_map<int,bool> dfsvisited;
    stack<int> st;
    bool ans=false;
    // for(int i=0;i<7;i++){
    //     if(visited[i]!=true){
    //         ans = g.DirectedCycleDetDFS(i,visited,dfsvisited);
    //         if(ans==true){
    //             break;
    //         }
    //     }
    // }
    g.topoDFS(0,visited,st);
    g.printGraph();
    cout<<"Topological Sort: ";
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
   

    return 0;
}