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


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int nodes,edges,u,v;
    bool flag=true;
    cin>>nodes>>edges;
    vector<pair<int,int> > subset(nodes+1);
    vector<list<int> > graph(nodes+1);
    for(int i=1;i<=edges;i++){
        cin>>u>>v;
        graph[u].push_back(v);
    }
    initialize(subset,nodes);
    pr(subset,nodes);
    for(int i=1;i<=nodes && flag;i++){
        list<int>::iterator itr;
        for(itr=graph[i].begin();itr!=graph[i].end() && flag;itr++){
            cout<<"i and *itr: "<<i<<"and"<<(*itr)<<endl;
            bool is_Same=find(subset,i,(*itr));
            if(is_Same)
                flag=false;
            else{
                _union(subset,i,(*itr));
                pr(subset,nodes);
            }
                
        }
    }
    if(flag)
        cout<<"No cycle";
    else
        cout<<"Has cycle";
    return 0;
}
