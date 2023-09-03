#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>
using namespace std;

class graph{
    public:
    unordered_map<int,list<pair<int,int>>> adj;

    void addNode(int u,int v,int w,int type){
        // type 0 -> Undirected
        // type 1 -> Directed
        adj[u].push_back({v,w});
        if(type==0){
            adj[v].push_back({u,w});
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


};

int main(){
    graph g;
    g.addNode(0,1,1,1);
    g.addNode(1,3,1,1);
    g.addNode(1,2,1,1);
    g.addNode(2,3,1,1);
    g.addNode(0,3,1,1);
    g.printGraph();
    return 0;
}