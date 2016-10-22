#include<bits/stdc++.h>
using namespace std;

void dfs(vector<list<int> > &graph, int u, vector<bool> &visited)
{
	visited[u]=true;
	list<int>::iterator itr;
	for(itr=graph[u].begin();itr!=graph[u].end();itr++){
		int v=(*itr);
		if(!visited[v])
		{
			dfs(graph,v,visited);
		}
	}
}

int main()
{
	int u,v,start,nodes,edges,connected_components=0;
	cin>>nodes>>edges;
    vector<list<int> >graph(nodes+1);
    vector<bool> visited(nodes+1,false);
    for(int i=1;i<=edges;i++){
    	cin>>u>>v;
    	graph[u].push_back(v);
    	graph[v].push_back(u);
    }
    for(int i=1;i<=nodes;i++)
    {
    	if(!visited[i])
    	{
    		dfs(graph,i,visited);
    		connected_components++;
    	}
    }
    cout<<connected_components;
    return 0;
}
