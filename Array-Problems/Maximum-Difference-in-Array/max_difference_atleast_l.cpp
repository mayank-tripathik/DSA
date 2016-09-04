#include<iostream>
using namespace std;
int main(){
	int test;
	cin>>test;
	while(test--){
		int n,difference,min,j,l;
		cin>>n;
		int arr[n];
		for(j=0;j<n;j++)
			cin>>arr[j];
				cin>>l;
		min=arr[0];
		difference=arr[l+1]-arr[0];
		for(j=l+1;j<n;j++){
			if(arr[j]-min>difference)
				difference=arr[j]-min;
			if(arr[j-l]<min)
				min=arr[j];
			}
		cout<<difference<<endl;
		}
	}
