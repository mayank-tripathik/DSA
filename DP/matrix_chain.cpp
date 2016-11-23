#include<bits/stdc++.h>
using namespace std;

int table[100][100];

void parenthesis(vector <int> &matrix, int i, int j){
    int size=matrix.size()-1;
    int min_product=INT_MAX;
    for(int k=i+1;k<=j;k++){
        int product=table[i][k-1]+table[k][j]+matrix[i]*matrix[k]*matrix[j+1];
        if(product<min_product)
            min_product=product;
    }
    table[i][j]=min_product;
}

void matrix_chain(vector<int> &matrix){
    int size=matrix.size()-1;
    for(int i=0;i<size;i++)
        table[i][i]=0;
    int i=-1;
    int j=1;
    while(j-i<size-1)
    {
        i++;
        if(i+j==size && j-i<size-1)
        {
            i=0;
            j++;
        }
        parenthesis(matrix,i,i+j);
    }
    cout<<"Minimum Multiplications:"<<table[0][size-1];
}

int main(){
    int n;
    cin>>n;
    vector<int> matrix(n+1);
    for(int i=0;i<n+1;i++)
        cin>>matrix[i];
    matrix_chain(matrix);  
    
}
