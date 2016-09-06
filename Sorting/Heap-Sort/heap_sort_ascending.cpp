/*------------------------Time Complexity : O(nlogn)------------------*/
/-----------------------Sorts array in ascending order------------------*/


#include <iostream>
using namespace std;

void top_down_heapify(int *arr,int n,int i){
	int left,right,max;
	while(2*i+1<n){
		left=2*i+1;
		right=2*i+2;
		if(right<n && arr[right]>arr[left])
			max=right;
		else
			max=left;
		if(arr[i]<arr[max]){
			swap(arr[i],arr[max]);
			i=max;
		}
		else
			break;
	}
	
}

//Building heap initially O(n) opeartion
void build_heap(int *arr, int n){    
	for(int i=(n-1)/2;i>=0;i--)
		top_down_heapify(arr,n,i);
}

void heap_sort(int *arr, int n){
	int size=n-1;
	build_heap(arr,n); 
	for(int i=n-1;i>=1;i--)
	{
		swap(arr[0],arr[i]);
		top_down_heapify(arr,size,0);
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
