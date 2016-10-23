#include <iostream>
using namespace std;

static int mat[20][20];
bool visited[20][20];
int n;
int count;

bool is_safe(int i,int j){
    if(i>=0 && i<n && j>=0 && j<n && mat[i][j]==0 && !visited[i][j])
        return true;
    else
        return false;
}
void dfs(int i, int j)
{
    cout<<"i:"<<i<<" j:"<<j<<endl;
    if(i==n-1 && j==n-1){
        count++;
        return;
    }
    
	visited[i][j]=true;
	if(is_safe(i+1,j))
		dfs(i+1,j);
	if(is_safe(i-1,j))
		dfs(i-1,j);
	if(is_safe(i,j+1))
		dfs(i,j+1);
	if(is_safe(i,j-1))
		dfs(i,j-1);
    cout<<"This is set false i:"<<i<<" j:"<<j<<endl;
    visited[i][j]=false;
}


int main()
{
    int test;
    cin>>test;
    while(test--)
    {
    	cin>>n;
    	for(int i=0;i<n;i++){
    		for(int j=0;j<n;j++){
                cin>>mat[i][j];
    			visited[i][j]=false;
            }	
    	}
        count=0;
    	/*for(int i=0;i<n;i++){
    		for(int j=0;j<n;j++)
    			cout<<mat[i][j];
    		cout<<endl;
    	}*/
    	dfs(0,0);
        cout<<count<<endl;
    }
    return 0;
}
