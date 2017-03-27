#include<bits/stdc++.h>
using namespace std;

void initialize(vector<pair<int,int> > &sub,int nodes){
    for(int i=1;i<=nodes;i++){
        sub[i].first=i;
        sub[i].second=0;
    }
}

void pr(vector<pair<int,int> > &sub,int nodes){
    for(int i=1;i<=nodes;i++){
        cout<<"node :"<<i<<" ;; Parent : "<<sub[i].first<<endl;
    }
}

int root(vector<pair<int,int> > &sub,int u){
    int parent=sub[u].first;
    while(parent!=u){
        u=parent;
        parent=sub[u].first;
    }
    return parent;
}

bool find(vector<pair<int,int> > &sub,int u,int v){
   if(root(sub,u)==root(sub,v))
       return true;
   else
       return false;
}

void _union(vector<pair<int,int> > &sub,int u,int v){
    int x=root(sub,u);
    int y=root(sub,v);
    sub[x].first=y;
}

bool mycom(const pair<int, pair<int, int> > &v1, const pair<int, pair<int, int> > &v2){
    if(v1.first<v2.first)
        return true;
    else if(v1.first>v2.first)
        return false;
    else
    {
        int x=v1.first+v1.second.first+v1.second.second;
        int y=v2.first+v2.second.first+v2.second.second;
        if(x<y)
            return true;
        else
            return false;
    }
}

int main() {
    int edges,nodes,u,v,weight,start,sum=0;
    cin>>nodes>>edges;
    vector<pair<int,pair<int,int> > > graph;
    vector<pair<int,int> > subset(nodes+1);
    for(int i=1;i<=edges;i++){
        cin>>u>>v>>weight;
        graph.push_back(make_pair(weight,make_pair(u,v)));
    }
    cin>>start;
    vector<pair<int,pair<int,int> > >::iterator it;
    sort(graph.begin(),graph.end(),mycom);
    int i=1;
    initialize(subset,nodes);
    for(it=graph.begin();it!=graph.end() && i<=edges-1;it++)
    {
        int u=(*it).second.first;
        int v=(*it).second.second;
        bool create_cycle=find(subset,u,v);
        if(!create_cycle)
        {
            _union(subset,u,v);
            sum+=(*it).first;
            i++;
        }
    }
    cout<<sum;
    return 0;
}



/************* Krushkal with Improved Disoint data set **********/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class DisjointSet{
    private:
        vector<int> parent;
        vector<int> rank;
    public:
        DisjointSet(int n)
        {
            parent.resize(n);
            rank.resize(n);
            for(int i=0;i<n;i++){
                parent[i]=i;
                rank[i]=1;
            }            
        }
        int findSet(int x)
        {
            while(parent[x]!=x)
                x=parent[x];
            return x;
        }
        void unionSet(int x, int y)
        {
            x=findSet(x);
            y=findSet(y);
            if(rank[x]>rank[y])
                parent[y]=x, rank[x] += rank[y];            
            else
                parent[x]=y, rank[y] += rank[x];     
        }
        bool isSameSet(int x, int y)
        {
            x=findSet(x);
            y=findSet(y);
            return x==y;
        } 
};


struct edge{
    int u,v,w;
    edge(int _src, int _dest, int _weight){
        u=_src;
        v=_dest;
        w=_weight;
    }
    bool operator < (const edge &e){
        return this->w<e.w;
    }
};

int main(){
    int nodes,edges,spanning_tree_weight=0;
    cin>>nodes>>edges;
    vector<edge> graph;
    for(int i=0;i<edges;i++){
        int u,v,w;
        cin>>u>>v>>w;
        graph.push_back(edge(u,v,w));
    }
    sort(graph.begin(),graph.end());
    DisjointSet ds(nodes+1);
    int edges_in_spanning_tree=nodes-1;
    for(int i=0;edges_in_spanning_tree;i++){
        if(!(ds.isSameSet(graph[i].u,graph[i].v))){
            ds.unionSet(graph[i].u,graph[i].v);
            spanning_tree_weight+=graph[i].w;
            edges_in_spanning_tree--;
        }
    }
    cout<<spanning_tree_weight<<endl;
}
