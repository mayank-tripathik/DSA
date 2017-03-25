#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;

int getmin(vector<bool> &status,vector<int> &dist){
    int min_cost=INT_MAX;
    int min_vertex=-1;
    int nodes=status.size();
    for(int i=0;i<nodes;i++){
        if(!status[i] && dist[i]<min_cost){
            min_vertex=i;
            min_cost=dist[i];
        }
    }
    return min_vertex;
}

void print(vector<int> &vec){
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<" ";
    }
    cout<<endl;
}

void djikshtra(vector<list<P> > &graph, int start){
    int nodes=graph.size();
    vector<bool> status(nodes,false);
    vector<int> dist(nodes,INT_MAX);
    vector<int> parent(nodes,-1);
    dist[start]=0;
    int unvisited=nodes;
    while(unvisited){
        int u=getmin(status,dist);
        if(u==-1)
            break;
        status[u]=true;
        unvisited--;
        for(auto itr=graph[u].begin();itr!=graph[u].end();itr++){
            int v=(*itr).first;
            int w=(*itr).second;
            if(dist[u]+w<dist[v]){
                dist[v]=dist[u]+w;
                parent[v]=u;
            }                
        }
    }
    cout<<"Parent Array:"<<endl;
    print(parent);
    cout<<"Shortest Distance Array:"<<endl;
    print(dist);   
}

int main(){
    int test;
    cin>>test;
    while(test--){
        int nodes,edges,start;
        cin>>nodes>>edges>>start;
        vector<list<P> >graph(nodes);
        for(int i=1;i<=edges;i++){
            int u,v,w;
            cin>>u>>v>>w;
            graph[u].push_back({v,w});
            graph[v].push_back({u,w});
        }
        djikshtra(graph,start);
    }    
}



/************* Djikshtra using priority queue to get minimum distance ***********/

#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;

void print(vector<int> &vec){
    for(int i=0;i<vec.size();i++){
        cout<<vec[i]<<" ";
    }
    cout<<endl;
}

struct compare
{
    bool operator()(pair<int,int> n1,pair<int,int> n2) {
        return n1.second>n2.second;
    }
};


void djikshtra(vector<list<P> > &graph, int start){
    int nodes=graph.size();
    vector<bool> status(nodes,false);
    vector<int> dist(nodes,INT_MAX);
    vector<int> parent(nodes,-1);
    priority_queue<P,vector<P>,compare> pq;
    dist[start]=0;
    pq.push({start,0});
    int unvisited=nodes;
    while(unvisited && !pq.empty()){
        pair<int,int> p=pq.top();
        pq.pop();
        int u=p.first;
        if(status[u]){
            continue;
        }
        else{
            status[u]=true;
            unvisited--;
            for(auto itr=graph[u].begin();itr!=graph[u].end();itr++){
                int v=(*itr).first;
                int w=(*itr).second;
                if(dist[u]+w<dist[v]){
                    dist[v]=dist[u]+w;
                    parent[v]=u;
                    pq.push({v,dist[v]});
                }                
            }
        }       
    }
    cout<<"Parent Array:"<<endl;
    print(parent);
    cout<<"Shortest Distance Array:"<<endl;
    print(dist);    
}

int main(){
    int test;
    cin>>test;
    while(test--){
        int nodes,edges,start;
        cin>>nodes>>edges>>start;
        vector<list<P> >graph(nodes);
        for(int i=1;i<=edges;i++){
            int u,v,w;
            cin>>u>>v>>w;
            graph[u].push_back({v,w});
            graph[v].push_back({u,w});
        }
        djikshtra(graph,start);
    }   
}
