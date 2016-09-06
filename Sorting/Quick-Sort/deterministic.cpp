
#include<iostream>
#include<vector>
#include<cstdlib>
#include<algorithm>
using namespace std;

int median(int arr[],int n){
	if(n<=5){
		if(n%2==0)
			return ((n/2)-1);
		else
			return(n/2);
	}
	else
	{
		int i,j,k;
		int n_group=n/5;
		i=0;
		for(j=0;j<n_group;j++){
			sort(arr+i,arr+(i+5));
			i=i+5;
		}
		sort(arr+(n_group*5),arr+n);
		for(i=0;i<n;i++)
			cout<<arr[i]<<" ";
		cout<<endl;
		i=2;
		for(k=0;k<n_group;k++){
			arr[k]=arr[i];
			i+=5;
		}
		int low=n_group*5;
		int size_last=n%5;
		if(size_last%2==0){
			arr[k]=arr[low+((size_last/2)-1)];
		}
		else
			arr[k]=arr[low+((size_last)/2)];
		for(i=0;i<n;i++)
			cout<<arr[i]<<" ";
		cout<<endl;
		sort(arr,arr+n_group+1);
		return median(arr,n_group+1);
	}
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
int quick_sort(int *arr,int l, int r,int rank){
	if(l<r){
		int pivot=median(arr[],r+l-1);
		cout<<"l:"<<l<<" and r: "<<r<<endl;
		cout<<"Pivot picked : "<<arr[pivot]<<endl;
		swap(arr[l],arr[pivot]);
		pivot=arr[l];
		int k=partition(arr,l,r,pivot);
		cout<<"Pivot's right place:"<<k<<endl;
		for(int i=l;i<=r;i++)
			cout<<arr[i]<<" ";
		cout<<endl;
		if(rank==r-k+1)
			return arr[k];
		else if(rank>r-k+1)
			return quick_sort(arr,l,k-1,rank-k);
		else
			return quick_sort(arr,k+1,r,rank);
	}
	else
		return arr[l];
}
int main() {
	int n,rank,element;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cin>>rank;
	element=quick_sort(arr,0,n-1,rank);
	cout<<"\nElement with rank "<<rank<<" is: ";
	cout<<element<<endl;;
	return 0;
}
