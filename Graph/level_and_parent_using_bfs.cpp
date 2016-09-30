#include<iostream>
#include<utility>
#include<vector>
#include<list>
#include<queue>
using namespace std;

int main(){
	int nodes,x,y,start,lev=1,count=0,flag;
	cin>>nodes;
	vector<list<int> > graph(nodes+1);
	list<int>:: iterator itr;
	for(int i=1;i<=nodes-1;i++){
		cin>>x>>y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	/*for(int i=1;i<=nodes;i++){
		itr=graph[i].begin();
		cout<<"Nodes connected to "<<i<<" are : ";
		while(itr!=graph[i].end()){
			cout<<*itr<<" ";
			++itr;
		}
		cout<<endl;
	}*/
	
	queue<int> visiting;
	vector<bool> visited(nodes+1,false);
	vector<int> level(nodes+1);
    vector<int> parent(nodes+1);
	cin>>x;
	start=1;
	visiting.push(start);
	level[start]=lev;
	flag=true;
	while(!visiting.empty()){
		int current=visiting.front();
		visiting.pop();
		visited[current]=true;
		itr=graph[current].begin();
		//cout<<"Visiting node : "<<current<<endl;
		if(flag)
			lev++;
		//cout<<"lev"<<lev<<endl;
		while(itr!=graph[current].end()){
			flag=false;
			if(!visited[*itr]){
				level[*itr]=lev;
                parent[*itr]=current;
				//cout<<*itr<<" ";
				visiting.push(*itr);
				//cout<<"level of "<<(*itr)<< "is:"<<lev<<endl;
				flag=true;
				
			}
			++itr;
		}
		//cout<<endl;
	}
	for(int i=1;i<=nodes;i++){
		cout<<"Level of node "<<i<<" is:"<<level[i]<<endl;
	}
    	for(int i=1;i<=nodes;i++){
		cout<<"parent of node "<<i<<" is:"<<parent[i]<<endl;
	}
	cout<<count;
	
}
