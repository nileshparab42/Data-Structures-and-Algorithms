#include<iostream>
#include<vector>
#include<unordered_map>
#include<list>

using namespace std;
template<typename T>
class graph{
    public:
    unordered_map<T,list<pair<T,int>>> adj;

    void addNode(T u,T v,int w,int type){
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
    graph<char> g;
    g.addNode('a','b',1,1);
    g.addNode('b','d',1,1);
    g.addNode('b','c',1,1);
    g.addNode('c','d',1,1);
    g.addNode('a','d',1,1);
    g.printGraph();
    return 0;
}