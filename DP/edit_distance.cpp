#include<bits/stdc++.h>
using namespace std;

int min(int x, int y, int z)
{
    return min(min(x, y), z);
}

void edit_distance(string str1, string str2){
    int row=str1.size()+1;
    int col=str2.size()+1;
    int table[row][col];
    for(int j=0;j<col;j++)
        table[0][j]=j;
    for(int j=1;j<row;j++)
        table[j][0]=j;
    for(int i=1;i<row;i++){
        for(int j=1;j<col;j++){
            if(str1[i-1]==str2[j-1])
                table[i][j]=table[i-1][j-1];
            else
                table[i][j]=min(table[i-1][j-1],table[i-1][j],table[i][j-1])+1;
        }
    }
    cout<<"Minimum Number of operations required:"<<table[row-1][col-1]<<endl;
    int i=row-1;
    int j=col-1;
    while(i>=0 && j>=0)
    {
        if(str1[i-1]!=str2[j-1])
        {
            if(table[i][j]==table[i-1][j]+1)
            {
                cout<<"Remove:"<<str1[i-1]<<endl;
                i--;
            }
            else if(table[i][j]==table[i-1][j-1]+1){
                cout<<"Replace:"<<str1[i-1]<<"-->"<<str2[j-1]<<endl;
                i--;
                j--;
            }    
            else
            {
                    cout<<"Insert:"<<str2[j-1]<<endl;
                    j--;     
            }
        }
        else
        {
            i--;
            j--;
        }
    }
}

int main(){
    string str1,str2;
    cin>>str1>>str2;
    edit_distance(str1,str2);
}
