/*------------------------Time Complexity : O(nlogn)-------------------------*/
/*------------------Merge sort is used to calculate inversions------------------------------*/

#include<iostream>
#include<vector>
using namespace std;

int merge(int *arr, int l, int r, int k){
	int i,j,inv_count=0;
	i=l;
	j=k+1;
	vector<int> aux;
	while(i<=k && j<=r)
	{
		if(arr[i]>arr[j])
		{
			aux.push_back(arr[j]);
			j++;
			inv_count=inv_count+(k+1-i);
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
	return inv_count;
}
int merge_sort(int *arr, int l,int r){
	int inv_count=0;
	if(l<r){
		int k;
		k=(l+r)/2;
		inv_count=merge_sort(arr,l,k);
		inv_count+=merge_sort(arr,k+1,r);
		inv_count+=merge(arr,l,r,k);
	}
	return inv_count;
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
		cout<<"Inversion count:"<<merge_sort(arr,0,n-1)<<endl;
		for(int j=0;j<n;j++)
			cout<<arr[j]<<" ";
	}
}
