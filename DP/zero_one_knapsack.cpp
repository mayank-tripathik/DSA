#include<bits/stdc++.h>
using namespace std;


int max(int a, int b){
    if(a<b)
        return b;
    else 
        return a;
}

int zero_one_knapsack(int total, vector<int> &weight, vector<int> &profit){
    int col=total+1;
    int row=weight.size();
    int table[row][col];
    for(int i=0;i<row;i++)
        table[i][0]=0;
    for(int j=1;j<col;j++){
        if(j<weight[0])
            table[0][j]=0;
        else
            table[0][j]=weight[0];
    }
    for(int i=1;i<row;i++){
        for(int j=1;j<col;j++){
            if(j>=weight[i]){
                table[i][j]=max(table[i-1][j],profit[i]+table[i-1][j-weight[i]]);
            }
            else
                table[i][j]=table[i-1][j];
        }
    }  
    return table[row-1][col-1];
}

int main(){;
    int total,n;
    cin>>n;
    vector<int> weight(n);
    vector<int> profit(n);
    for(int i=0;i<n;i++){
        cin>>weight[i]>>profit[i];
    }
    cin>>total;
    cout<<"Maximum Profit is:"<<zero_one_knapsack(total, weight, profit);
}
