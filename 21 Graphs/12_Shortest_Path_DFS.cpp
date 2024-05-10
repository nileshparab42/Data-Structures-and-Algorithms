#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<queue>
#include<algorithm>
#include<limits.h>
#include<stack>
using namespace std;

class graph{
    public:
    unordered_map<int,list<pair<int,int>>> adj;

    void addNode(int u,int v,int dist,int type){
        // type 0 -> Undirected
        // type 1 -> Directed
        adj[u].push_back({v,dist});
        if(type==0){
            adj[v].push_back({u,dist});
        }
    } 

    void printGraph(){
        for(auto node:adj){
            cout<<node.first<<": ";
            for(auto neb:node.second){
                cout<<"("<<neb.first<<","<<neb.second<<")";
            }
            cout<<endl;
        }
    }
   

    void topoDFS(int src,unordered_map<int,bool>& visited,stack<int>& st){
        visited[src]=true;
        // cout<<src<<" ";
        for(auto i:adj[src]){
            if(visited[i.first]!=true){
                topoDFS(i.first,visited,st);
            }
        }
        st.push(src);
    }

    void shDFS(stack<int>& st,int n){
        vector<int> dist(n,INT_MAX);
        int node = st.top();
        st.pop();
        dist[node] = 0;        
        if(dist[node]!=INT_MAX){
                for(auto neb:adj[node]){
                    if(dist[node] + neb.second < dist[neb.first]){
                        dist[neb.first] = dist[node] + neb.second;
                    }
                }
            }
        while(!st.empty()){
            int node = st.top();
            st.pop();
            // cout<<node;
    
            if(dist[node]!=INT_MAX){
                for(auto neb:adj[node]){
                    if(dist[node] + neb.second < dist[neb.first]){
                        dist[neb.first] = dist[node] + neb.second;
                    }
                }
            }
        }

        cout<<"\nDistances: ";
        for(int i=0;i<n;i++){
            cout<<i<<"->"<<dist[i]<<" ";
        }

    }


};





int main(){
    graph g;
    g.addNode(0,1,5,1);
    g.addNode(0,2,3,1);
    g.addNode(1,3,3,1);
    g.addNode(2,1,2,1);
    g.addNode(2,3,5,1);
    g.addNode(2,4,6,1);
    g.addNode(4,3,1,1);
    // g.printGraph();
    stack<int> st;
    unordered_map<int,bool> visited;
    g.topoDFS(0,visited,st);
    g.shDFS(st,5);
    

   
   

    return 0;
}