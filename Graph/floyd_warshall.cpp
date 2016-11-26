#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;

void floyd_warshall(vector<pair<P,int> > &graph, int nodes){
    int dist[nodes][nodes];
    int path[nodes][nodes];
    /*Initialising path and distance matrix*/
    for(int i=0;i<nodes;i++){
        for(int j=0;j<nodes;j++){
            dist[i][j]=INT_MAX;
            path[i][j]=-1;
        }   
    }
    for(int i=0;i<nodes;i++)
        dist[i][i]=0;
    for(int i=0;i<graph.size();i++){
        int u=graph[i].first.first;
        int v=graph[i].first.second;
        int weight=graph[i].second;
        dist[u][v]=weight;
        path[u][v]=u;
    }
    /*Main Algorithm*/
    for(int k=0;k<nodes;k++){
        for(int i=0;i<nodes;i++){
            for(int j=0;j<nodes;j++){
                if(dist[i][k]==INT_MAX || dist[k][j]==INT_MAX)
                    continue;
                if(dist[i][j]>dist[i][k]+dist[k][j]){
                    dist[i][j]=dist[i][k]+dist[k][j];
                    path[i][j]=path[k][j];
                }
            }
        }
    }
    /*Printing*/
    cout<<"Distance Matrix:\n";
    for(int i=0;i<nodes;i++){
        for(int j=0;j<nodes;j++){
            cout<<dist[i][j]<<" ";
        }
        cout<<endl;
    }
     cout<<"Path Matrix:\n";
    for(int i=0;i<nodes;i++){
        for(int j=0;j<nodes;j++){
            cout<<path[i][j]<<" ";
        }
        cout<<endl;
    }
}
    
int main(){
    int nodes,edges;
    cin>>nodes>>edges;
    vector<pair<P,int> > graph;
    for(int i=0;i<edges;i++){
        int u,v,weight;
        cin>>u>>v>>weight;
        graph.push_back({{u,v},weight});
    }
    floyd_warshall(graph,nodes);
}
