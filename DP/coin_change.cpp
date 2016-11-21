#include<bits/stdc++.h>
using namespace std;


int min(int a, int b){
    if(a<b)
        return a;
    else 
        return b;
}

int coin_change(int total, vector<int> &denom){
    int col=total+1;
    int row=denom.size();
    int table[row][col];
    for(int i=0;i<row;i++)
        table[i][0]=0;
    for(int j=1;j<col;j++)
        table[0][j]=j;
    for(int i=1;i<row;i++){
        for(int j=1;j<col;j++){
            if(j>=denom[i]){
                table[i][j]=min(table[i-1][j],1+table[i][j-denom[i]]);
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
    vector<int> denom(n);
    for(int i=0;i<n;i++){
        cin>>denom[i];
    }
    cin>>total;
    cout<<"Minimum Number of coins required are:"<<coin_change(total, denom);
}
