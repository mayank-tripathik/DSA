#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int test;
	cin>>test;
	while(test){
		int n,x,i,j;
		cin>>n;
		int arr[n];
		cin>>x;
		for(i=0;i<n;i++)
			cin>>arr[i];
		sort(arr,arr+n);
		i=0;
		j=n-1;
		while(i<=j){
			if(arr[i]+arr[j]==x)
				break;
			else if(arr[i]+arr[j]>x)
				j--;
			else if(arr[i]+arr[j]<x)
				i++;
			}
		if(i>j)
			cout<<"False\n";
		else
			cout<<"True\n";
		}
}
