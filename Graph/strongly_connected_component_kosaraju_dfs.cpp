#include<bits/stdc++.h>
using namespace std;

stack<int> finish;
int n_connected_component;

int dfs(vector<list<int> > &graph, int u, vector<bool> &visited,int flag){
    visited[u]=true;
    if(flag==0)
        cout<<u<<" ";
    list<int>:: iterator itr;
    for(itr=graph[u].begin();itr!=graph[u].end();itr++){
        int v=(*itr);
        if(!visited[v]){
            n_connected_component++;
            dfs(graph,v,visited,flag);
        }
    }
    if(flag==1)
        finish.push(u);
    return n_connected_component;
}


vector<list<int> > transpose(vector<list<int> > &graph){
    int nodes=graph.size()-1;
    vector<list<int> > tgraph(nodes+1);
    for(int i=1;i<=nodes;i++){
        int u=i;
        list<int>::iterator itr;
        for(itr=graph[u].begin();itr!=graph[u].end();itr++){
            int v=(*itr);
            tgraph[v].push_back(u);
        }
    }
    return tgraph;
}

void reset(vector<bool> &visited){
    for(int i=1;i<visited.size();i++)
        visited[i]=false;
}

int main(){
    int nodes,edges;
    cin>>nodes>>edges;
    vector<bool> visited(nodes+1,false);
    vector<list<int> > graph(nodes+1);
    bool flag;
    for(int i=1;i<=edges;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
    }
    dfs(graph,1,visited,1);
    vector<list<int> > transpose_graph=transpose(graph);
    reset(visited);
    while(!finish.empty()){
        int u=finish.top();
        finish.pop();
        if(!visited[u]){
            n_connected_component=1;
            cout<<"Connected components: ";
            n_connected_component=dfs(transpose_graph,u,visited,0);
            cout<<endl<<"No of nodes in this component:"<<n_connected_component<<endl<<endl;  
        }
            
    }
}
