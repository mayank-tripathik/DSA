/*---------------------------Time complexity = O(nlogn)---------------------------------**/
/*--------------This implimentation uses good pivot which is found by median of median algorithm-----------*/

#include<iostream>
#include<vector>
#include<cstdlib>
#include<algorithm>
using namespace std;

void printarr(int *arr, int low, int high){
	for(int i=low;i<=high;i++)
		cout<<arr[i]<<" ";
	cout<<endl;

}

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
	int i=low;
	for(int j=low+1;j<=high;j++)
	{
		if(arr[j]<pivot)
		{
			i++;
			swap(arr[i],arr[j]);   
		}
	}
	swap(arr[low],arr[i]);
	return i;
}


void quick_sort(int *arr,int l, int r){
	if(l<r){
		int pivot=median_of_median(arr,l,r);
		swap(arr[l],arr[pivot]);
		pivot=arr[l];
        cout<<"pivot:"<<pivot<<endl;
        printarr(arr,l,r);
		int k=partition(arr,l,r,pivot);
        cout<<"position:"<<k<<endl;
        printarr(arr,l,r);
		quick_sort(arr,l,k-1);
		quick_sort(arr,k+1,r);
	} 
}

int main() 
{
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	cout<<"Given Array:\n";
	printarr(arr,0,n-1);
	quick_sort(arr,0,n-1);
	cout<<"Sorted Array:\n";
	printarr(arr,0,n-1);
    return 0;
}
