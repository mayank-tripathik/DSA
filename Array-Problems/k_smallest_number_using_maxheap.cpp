#include<iostream>
#include<cstdlib>
using namespace std;

void printarray(int *arr,int k, int n){
	cout<<"Array:\n";
	for(int i=0;i<k;i++)
		cout<<arr[i]<<" ";
	cout<<"  ";
	for(int i=k;i<n;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}
void top_down_heapify(int *arr,int k, int i){
	while(2*i+1<k){
		int l=2*i+1;
		int r=2*i+2;
		int max;
		if(r<k && arr[r]>arr[l])
			max=r;
		else
			max=l;
		if(arr[i]<arr[max]){
			swap(arr[i],arr[max]);
			i=max;
		}
		else
			break;
	}
}
void build_max_heap(int *arr, int k){
	for(int i=(k/2)-1;i>=0;i--){
		top_down_heapify(arr,k,i);
	}
}
void find_k_smallest(int *arr, int k, int n){
	build_max_heap(arr,k);
	cout<<"Max heap with k elements"<<endl;
	printarray(arr,k,n);
	for(int i=k;i<n;i++){
		//cout<<"next num:"<<arr[i]<<endl;
		if(arr[i]<arr[0]){
			arr[0]=arr[i];
			top_down_heapify(arr,k,0);
		}
		//printarray(arr,k,n);
	}
}
int main(){
	int n,k,i;
	cin>>n;
	int arr[n];
	for(i=0;i<n;i++){
		int x=rand()%(n);
		arr[i]=x;
	}
	cin>>k;
	find_k_smallest(arr,k,n);
	cout<<"k smallest number are:\n";
	for(i=0;i<k;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}
