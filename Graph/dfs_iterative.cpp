#include<bits/stdc++.h>
using namespace std;

void dfs(vector<list<int> >&graph, int start, vector<bool> &visited)
{
	stack<int> mystack;
	mystack.push(start);
	while(!mystack.empty()){
		int u=mystack.top();
		mystack.pop();
		visited[u]=true;
		cout<<"visiting vertex:"<<u<<endl;
		list<int>::iterator itr;
		for(itr=graph[u].begin();itr!=graph[u].end();itr++){
			int v=(*itr);
			if(!visited[v]){
				mystack.push(v);
			}
		}
	}
}

int main()
{
    int u,v,start,nodes,edges;
    cin>>nodes>>edges;
    vector<list<int> >graph(nodes+1);
    vector<bool> visited(nodes+1,false);
    for(int i=1;i<=edges;i++){
    	cin>>u>>v;
    	graph[u].push_back(v);
    	graph[v].push_back(u);
    }
    cin>>start;
    dfs(graph,start,visited);
    return 0;
}
