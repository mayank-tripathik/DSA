#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;

void print(vector<int> &vec){
    for(int i=1;i<vec.size();i++)
        cout<<vec[i]<<" ";
    cout<<endl;
}

void bellman_ford(vector<pair<P,int> > &graph, int start, int nodes){
    int edges=graph.size();
    vector<int> dist(nodes+1,INT_MAX);
    vector<int> parent(nodes+1);
    dist[start]=0;
    for(int i=1;i<=nodes-1;i++){
       for(int i=0;i<edges;i++){
           int u=graph[i].first.first;
           int v=graph[i].first.second;
           int weight=graph[i].second;
           if(dist[u]+weight<dist[v]){
               dist[v]=dist[u]+weight;
               parent[v]=u;
           }
        }
        
    }
    for(int i=0;i<edges;i++){
        int u=graph[i].first.first;
        int v=graph[i].first.second;
        int weight=graph[i].second;
        if(dist[u]+weight<dist[v]){
            cout<<"Negative weighted cycle!"<<endl;
        }
    }
    print(dist);
    print(parent);
}

int main(){
    int nodes,edges,start;
    cin>>nodes>>edges;
    vector<pair<P,int> > graph;
    for(int i=0;i<edges;i++){
        int u,v,weight;
        cin>>u>>v>>weight;
        graph.push_back({{u,v},weight});
    }
    cin>>start;
    bellman_ford(graph,start,nodes);
}
