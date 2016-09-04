#include<iostream>
#include<vector>
using namespace std;

void merge(int *arr, int l, int r, int k){
	int i,j;
	i=l;
	j=k+1;
	vector<int> aux;
	while(i<=k && j<=r)
	{
		if(arr[i]>arr[j])
		{
			aux.push_back(arr[j]);
			j++;
		}
		else
		{
			aux.push_back(arr[i]);
			i++;
		}
	}
	while(i<=k){
		aux.push_back(arr[i]);
		i++;
	}
	while(j<=r){
		aux.push_back(arr[j]);
		j++;
	}
	j=0;
	for(i=l;i<=r;i++){
		arr[i]=aux[j];
		j++;
	}
}
void merge_sort(int *arr, int l,int r){
	if(l<r){
		int k;
		k=(l+r)/2;
		merge_sort(arr,l,k);
		merge_sort(arr,k+1,r);
		merge(arr,l,r,k);
	}
}
int main(){
	int test;
	cin>>test;
	while(test--){
		int n;
		cin>>n;
		int arr[n];
		for(int j=0;j<n;j++)
			cin>>arr[j];
		merge_sort(arr,0,n-1);
		for(int j=0;j<n;j++)
			cout<<arr[j]<<" ";
	}
}
