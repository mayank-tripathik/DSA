#include <iostream>
#include<vector>
using namespace std;

int pick_pivot(int l,int r){
	return (l+r)/2;
}

int partition(int *arr,int l,int r, int pivot){
	vector<int> smaller,bigger;
	int i,j,k;
	for(i=l+1;i<=r;i++){
		if(arr[i]<pivot)
			smaller.push_back(arr[i]);
		else if(arr[i]>pivot)
			bigger.push_back(arr[i]);
	}
	i=l;
	for(j=0;j<smaller.size();j++){
		arr[i++]=smaller[j];
	}
	arr[i]=pivot;
	k=i;
	i++;
	for(j=0;j<bigger.size();j++){
		arr[i++]=bigger[j];
	}
	return k;
}
void quick_sort(int *arr,int l, int r){
	if(l<r){
		int pivot=pick_pivot(l,r);
		cout<<"l:"<<l<<" and r: "<<r<<endl;
		cout<<"Pivot picked : "<<arr[pivot]<<endl;
		swap(arr[l],arr[pivot]);
		pivot=arr[l];
		int k=partition(arr,l,r,pivot);
		cout<<"Pivot's right place:"<<k<<endl;
		for(int i=l;i<=r;i++)
			cout<<arr[i]<<" ";
		cout<<endl;
		quick_sort(arr,l,k-1);
		quick_sort(arr,k+1,r);
	}
}
int main() {
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cout<<"Given Array:\n";
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl<<endl;
	quick_sort(arr,0,n-1);
	cout<<"\nSorted Array:\n";
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	return 0;
}
