#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
#include<queue>
#include<algorithm>
#include<set>
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


    void dijkstraSp(int src,int n){
        vector<int> dist(n,INT_MAX);
        set<pair<int,int>> st;

        st.insert({0,src});
        dist[src]=0;

        while(!st.empty()){
            auto toppair = *(st.begin());
            st.erase(st.begin());
            int node = toppair.second;
            int distnode = toppair.first;

            for(auto neb:adj[node]){
                if(distnode + neb.second < dist[neb.first]){
                    auto res = st.find({dist[neb.first],neb.first});
                    if(res!=st.end()){
                        st.erase({dist[neb.first],neb.first});
                    }
                    dist[neb.first] = distnode + neb.second;
                    st.insert({dist[neb.first],neb.first});
                }
            }
        }
        cout<<"\nDistances form src : ";
        for(int i=0;i<n;i++){
            cout<<dist[i]<<" ";
        }

    }


};





int main(){
    graph g;
    g.addNode(5,6,9,0);
    g.addNode(5,4,6,0);
    g.addNode(6,3,2,0);
    g.addNode(3,4,11,0);
    g.addNode(6,1,14,0);
    g.addNode(3,1,9,0);
    g.addNode(3,2,10,0);
    g.addNode(4,2,15,0);
    g.addNode(1,2,7,0);
    // g.printGraph();

    g.dijkstraSp(6,7);
    
    

   
   

    return 0;
}