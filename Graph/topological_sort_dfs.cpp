#include<bits/stdc++.h>
using namespace std;

stack<int> finish;

void dfs(vector<list<int> > &graph, int u, vector<bool> &visited){
    visited[u]=true;
    list<int>:: iterator itr;
    for(itr=graph[u].begin();itr!=graph[u].end();itr++){
        int v=(*itr);
        if(!visited[v]){
            dfs(graph,v,visited);
        }
    }
    finish.push(u);
}

void topological_sort(vector<list<int> > &graph){
    int nodes=graph.size()-1;
    vector<bool> visited(nodes+1,false);
    for(int i=1;i<=nodes;i++){
        if(!visited[i])
            dfs(graph,i,visited);
    }
    cout<<"Following is a Topological Sort of the given graph:"<<endl;
    while(!finish.empty()){
        int u=finish.top();
        finish.pop();
        cout<<u<<" ";
    }
}

int main(){
    int nodes,edges;
    cin>>nodes>>edges;;
    vector<list<int> > graph(nodes+1);
    for(int i=1;i<=edges;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
    }
    topological_sort(graph);
}
