#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cout<<"Enter Number of Vertex:";
    cin>>n;
    int e;
    cout<<"Enter Number of Edges:";
    cin>>e;
    vector<vector<int> > graph(n,vector<int>(n,0));
    for(int i=0;i<e;i++){
        int u,v,w;
        cin>>u>>v>>w;
        graph[u][v]=w;

    }
    for(int i=0;i<graph.size();i++){
        for(int j=0;j<graph[0].size();j++){
            cout<<graph[i][j];
        }
        cout<<endl;
    }
    return 0;
}