#include<bits/stdc++.h>
using namespace std;


int min(int a, int b){
    if(a<b)
        return a;
    else 
        return b;
}

int subset_sum(int total, vector<int> &elem){
    int col=total+1;
    int row=elem.size();
    bool table[row][col];
    for(int i=0;i<row;i++)
        table[i][0]=true;
    for(int j=1;j<col;j++)
        table[0][j]=false;
    table[0][elem[0]]=true;
    for(int i=1;i<row;i++){
        for(int j=1;j<col;j++){
            if(j>=elem[i]){
                table[i][j]=table[i-1][j] || table[i-1][j-elem[i]];
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
    vector<int> elements(n);
    for(int i=0;i<n;i++){
        cin>>elements[i];
    }
    cin>>total;
    cout<<"Is subset available for this sum? : ";
    bool has_sum=subset_sum(total, elements);
    if(has_sum)
        cout<<"True";
    else
        cout<<"False";
}
