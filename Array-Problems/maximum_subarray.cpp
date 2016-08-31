#include<iostream>
using namespace std;
int main(){
	int test;
	cin>>test;
	while(test--)
	{
		int n,i,j,k,current_sum,max_sum;
		cin>>n;
		int arr[n];
		for(i=0;i<n;i++)
			cin>>arr[i];
		i=0;
		max_sum=current_sum=0;
		for(k=0;k<n;k++)
		{
			current_sum+=arr[k];
			if(current_sum>max_sum){
				max_sum=current_sum;
				j=k;
				}
			if(current_sum<0)
			{
				current_sum=0;
				i=k+1;
			}
		}
		cout<<"Maximum:"<<max_sum<<endl;
		cout<<"i:"<<i<<" and j:"<<j<<endl;  //i and j store index between which maximum sum is found.
	}
}
