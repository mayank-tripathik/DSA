#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;

int getmin(vector<bool> &status,vector<int> &dist){
    int min_cost=INT_MAX;
    int min_vertex=-1;
    int nodes=status.size()-1;
    for(int i=1;i<=nodes;i++){
        if(!status[i] && dist[i]<min_cost){
            min_vertex=i;
            min_cost=dist[i];
        }
    }
    return min_vertex;
}

void print(vector<int> &vec){
    for(int i=1;i<vec.size();i++){
        cout<<vec[i]<<" ";
    }
    cout<<endl;
}

void djikshtra(vector<list<P> > &graph, int start){
    int nodes=graph.size()-1;
    int sum=0;
    vector<bool> status(nodes+1,false);
    vector<int> dist(nodes+1,INT_MAX);
    vector<int> parent(nodes+1,-1);
    dist[start]=0;
    int unvisited=nodes;
    for(int i=1;i<=nodes;i++){
        int u=getmin(status,dist);
        status[u]=true;
        unvisited--;
        sum+=dist[u];
        //print(dist);
        for(auto itr=graph[u].begin();itr!=graph[u].end();itr++){
            int v=(*itr).first;
            int w=(*itr).second;
            if(w<dist[v]){
                dist[v]=w;
                parent[v]=u;
            }
                
        }
    }
    /*cout<<"Parent Array:"<<endl;
    print(parent);
    cout<<"Shortest Distance Array:"<<endl;
    print(dist);*/
    cout<<sum<<endl;
    
}

int main(){
    int nodes,edges,start;
    cin>>nodes>>edges;
    vector<list<P> >graph(nodes+1);
    for(int i=1;i<=edges;i++){
        int u,v,w;
        cin>>u>>v>>w;
        graph[u].push_back({v,w});
        graph[v].push_back({u,w});
    }
    cin>>start;
    djikshtra(graph,start);
}


/******** * Getting min using priority queue******/

#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;


void print(vector<int> &vec){
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<" ";
    }
    cout<<endl;
}

void prim_minimum_spanning_tree(vector<vector<P> > &graph, int start){
    int nodes=graph.size();
    vector<int> dist(nodes,INT_MAX);
    vector<bool> visited(nodes,false);
    vector<int> parent(nodes,-1);
    priority_queue<P,vector<P>,greater<P> > pq;
    dist[start]=0;
    pq.push({0,start});
    while(!pq.empty()){
        P qfront=pq.top();
        int u=qfront.second;
        pq.pop();
        if(!visited[u]){
            visited[u]=true;
            for(int i=0;i<graph[u].size();i++){
                P p=graph[u][i];
                int w=p.second;
                int v=p.first;
                if(!visited[v] && w<dist[v]){
                    dist[v]=w;
                    parent[v]=u;
                    pq.push({w,v});
                }
                
            }
        }
    }
    cout<<"Parent array:"<<endl;
    print(parent);
}

int main(){
    int test;
    cin>>test;
    int caseno=0;
    while(test--){
        int nodes,edges,start;
        cin>>nodes>>edges;
        vector<vector<P> >graph(nodes);
        for(int i=1;i<=edges;i++){
            int u,v,w;
            cin>>u>>v>>w;
            if(u!=v){
                graph[u].push_back({v,w});
                graph[v].push_back({u,w});
            }
        }
        start=0;
        prim_minimum_spanning_tree(graph,start);
    }    
}
