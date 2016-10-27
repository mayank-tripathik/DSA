#include<bits/stdc++.h>
using namespace std;
typedef list<int> L;

void print_graph(vector<L> &graph){
    int nodes=graph.size()-1;
    for(int i=1;i<=nodes;i++){
        int u=i;
        cout<<"u:"<<u<<" , v : ";
        for(auto itr=graph[u].begin();itr!=graph[u].end();itr++){
            int v=(*itr);
            cout<<v<<" ";
        }
        cout<<endl;
        
    }
}

int main(){
    int nodes,queries;
    cin>>nodes;
    vector<L> graph(nodes+1);
    for(int i=1;i<=nodes;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    print_graph(graph);
}
