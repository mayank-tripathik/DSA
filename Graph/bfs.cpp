/*
 * Implimentation of bfs using adjacency list(using STL)
 * Time Complexity O(V*E) which can be O(V^2) in worst case
 * Space Complexity: O(V) , Queue is used
*/

#include<iostream>
#include<utility>
#include<vector>
#include<list>
#include<queue>
using namespace std;

int main(){
	int nodes,x,y,start;
	cin>>nodes;
	vector<list<int> > graph(nodes+1);
	list<int>:: iterator itr;
	for(int i=1;i<=nodes-1;i++){
		cin>>x>>y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	queue<int> visiting;
	vector<bool> visited(nodes+1,false);
    cin>>start; 
	visiting.push(start);
    cout<<"Nodes are visited in the following order starting from vertex "<<start<<endl;
	while(!visiting.empty()){
		int current=visiting.front();
		visiting.pop();
		visited[current]=true;
		itr=graph[current].begin();
		while(itr!=graph[current].end()){
			if(!visited[*itr]){
                cout<<*itr<<endl;
				visiting.push(*itr);	
			}
			++itr;
		}
	}
	
}
