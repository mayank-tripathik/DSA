#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<vector>
#include<list>
#include<utility>
using namespace std;


int main() {
    int edges,nodes,u,v,weight;
    cin>>nodes>>edges;
    vector<list<pair<int,int> > >graph(nodes+1);
    for(int i=1;i<=edges;i++){
        cin>>u>>v>>weight;
        graph[u].push_back(make_pair(v,weight));
    }
    for(int i=1;i<=nodes;i++){
        list<pair<int,int> >::iterator itr;
        for(itr=graph[i].begin();itr!=graph[i].end();itr++){
            cout<<i<<" "<<(*itr).first<<" "<<(*itr).second<<endl;
        }
    }
    
    return 0;
}
