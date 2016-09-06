#include <iostream>
using namespace std;

void min_heapify(int *arr,int n,int i){
	int left,right,min;
	while(2*i+1<n){
		left=2*i+1;
		right=2*i+2;
		if(right<n && arr[right]<arr[left])
			min=right;
		else
			min=left;
		if(arr[i]>arr[min])
		{
			swap(arr[i],arr[min]);
			i=min;
		}
		else
			break;
	}
	
}

void build_heap(int *arr, int n){
	for(int i=(n-1)/2;i>=0;i--)
		min_heapify(arr,n,i);
}

void heap_sort(int *arr, int n){
	int size=n-1;
	build_heap(arr,n);
	for(int i=n-1;i>=1;i--)
	{
		swap(arr[0],arr[i]);
		min_heapify(arr,size,0);
		size--;
	}
}

int main() {
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cout<<"Unsorted Array:\n";
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	heap_sort(arr,n);
	cout<<"Sorted Array :\n";
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	return 0;
}
