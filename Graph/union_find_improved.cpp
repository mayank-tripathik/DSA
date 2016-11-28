#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void initialize(vector<int> &subset){
    for(int i=0;i<subset.size();i++)
        subset[i]=i;
}

void pr(vector<int> &subset){
    for(int i=0;i<subset.size();i++)
        cout<<subset[i]<<" ";
}


int root(vector<int> &subset, int u){
    int child=u;
    while(subset[u]!=u){
        u=subset[u];
    }
    subset[child]=u;
    return u;
}

bool find(vector<int> &subset, int u, int v){
    if(root(subset,u)==root(subset,v))
        return true;
    else
        return false;
}

void unite(vector<int> &subset, int u, int v,vector<int> &count){
    int x=root(subset,u);
    int y=root(subset,v);
    subset[x]=y;
}

int main() {
    int n,e,u,v;
    long long product=0;
    cin>>n>>e;
    vector<int> subset(n);
    vector<int> count(n,0);
    initialize(subset);
    for(int i=0;i<e;i++){
        cin>>u>>v;
        bool same_subset=find(subset,u,v);
        if(!same_subset)
            unite(subset,u,v,count);
    }
    for(int i=0;i<n;i++){
        int x=root(subset,i);
        count[x]++;
    }
    vector<int> repeat;
    for(int i=0;i<n;i++){
        if(count[i]!=0)
            repeat.push_back(count[i]);
    }
    vector<int> repeat_sum(repeat.size()-1);
    int repeat_s=0;
    for(int i=repeat_sum.size()-1;i>=0;i--){
        repeat_s+=repeat[i+1];
        repeat_sum[i]=repeat_s;
    }
    for(int i=0;i<repeat.size()-1;i++){
        product+=repeat[i]*repeat_sum[i];
    }
    cout<<product;
    return 0;
}
