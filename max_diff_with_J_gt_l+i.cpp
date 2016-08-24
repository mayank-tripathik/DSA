#include<iostream>
using namespace std;
int main(){
	int test;
	cin>>test;
	while(test--){
		int n,max,min,j,l;
		cin>>n;
		int arr[n];
		cin>>l;
		for(j=0;j<n;j++)
			cin>>arr[j];
		min=arr[0];
		max=arr[l+1]-arr[0];
		for(j=l+1;j<n;j++){
			if(arr[j]-min>max)
				max=arr[j]-min;
			if(arr[j-l]<min)
				min=arr[j];
			}
		cout<<max<<endl;
		}
	}
