/*---------------This algorithm finds kth largest element or (n-k)th smallest elment---------------*/
/*-----------This algorithms can also be seen as an algorithm for returning element whose rank is k ---------------*/
/*-----------------Time complexity: O(n^2) in worst case, O(n) on average--------------------------*/

#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;

int pick_pivot(int l,int r){
	return (rand()%(r-l)+l);
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
