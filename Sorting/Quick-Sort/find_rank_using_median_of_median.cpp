/*---------------This algorithm finds kth largest element or (n-k+1)th smallest elment---------------*/
/*-----------This algorithms can also be seen as an algorithm for returning element whose rank is k ---------------*/
/*-----------------Time complexity: O(n) in worst case, O(n) on average--------------------------*/

#include<iostream>
#include<vector>
#include<cstdlib>
#include<algorithm>
using namespace std;

int median_of_median(int *arr,int low,int high)
{
	if(high-low+1>=5)
	{
		int n=high-low+1;    //size of current array
		int num_groups=n/5;  //numbers of groups with 5 elements
		int rem_elem=n%5;    //number of elements in last group
		int start_index=low,end_index=low+4;
		int index_median=low;
		for(int i=0;i<num_groups;i++)
		{
            		sort(arr+start_index,arr+end_index+1);
			swap(arr[index_median],arr[(start_index+end_index)/2]);
			index_median++;
			start_index=end_index+1;
			end_index=end_index+5;
		}
		if(rem_elem>0)
		{
			int low_index=num_groups*5+low;
            		sort(arr+low_index,arr+high+1);
			swap(arr[index_median],arr[low_index+(rem_elem/2)]);
		}
		return median_of_median(arr,low,index_median-1);	
	}
	else
	{
		return ((low+high)/2);
	}
 
}

int partition(int *arr,int low,int high, int pivot){
	int i=low+1;
	int j=high;
	while(i<=j){
		while(arr[i]<pivot && i<=high)
			i++;
		while(arr[j]>pivot && j>=low)
			j--;
		if(i<j)
		{
			swap(arr[i],arr[j]);
			i++;
			j--;	
		}
		else
			break;
		
	}
	swap(arr[low],arr[j]);
	return j;
}

int kth_largest(int *arr,int l, int r,int rank){
	if(l<r){
		int pivot=median_of_median(arr,l,r);
		//cout<<"l:"<<l<<" and r: "<<r<<endl;
		//cout<<"Pivot picked : "<<arr[pivot]<<endl;
		swap(arr[l],arr[pivot]);
		pivot=arr[l];
		int k=partition(arr,l,r,pivot);
		//cout<<"Pivot's right place:"<<k<<endl;
		if(rank==r-k+1)
			return arr[k];
		else if(rank>r-k+1)
			return kth_largest(arr,l,k-1,rank-(r-k+1));
		else
			return kth_largest(arr,k+1,r,rank);
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
	element=kth_largest(arr,0,n-1,rank);
	cout<<"\nElement with rank "<<rank<<" OR "<<rank<<"th largest element"<<" OR "<<n-rank+1<<"th smallest element is: ";
	cout<<element<<endl;;
	return 0;
}
