/*------------------This algorithm finds k smallest elements in array---------------*/
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

int find_elem_rank(int *arr,int l, int r,int rank){
	if(l<r){
		int pivot=median_of_median(arr,l,r);
		swap(arr[l],arr[pivot]);
		pivot=arr[l];
		int k=partition(arr,l,r,pivot);
		if(rank==r-k+1)
			return arr[k];
		else if(rank>r-k+1)
			return find_elem_rank(arr,l,k-1,rank-(r-k+1));
		else
			return find_elem_rank(arr,k+1,r,rank);
	}
	else
		return arr[l];
}

void find_k_smallest(int *arr,int k, int n){
    int pivot,j,pos,i;
    if(2*k>n){
        sort(arr,arr+n);
    }
    else
    {
        find_elem_rank(arr,0,2*k-1,k);
        j=2*k;
        i=k;
        while(j<n)
        {
            while(i<2*k)
            {
                arr[i]=arr[j];
                j++;
                i++;
                if(j>=n)
                    break;
            }
            find_elem_rank(arr,0,i,k);
            i=k;
        }    
    }
}

int main(){
	int n,k,i,j;
	cin>>n;
    cin>>k;
	int arr[n];
    j=0;
	for(i=n;i>=1;i--){
		int x=rand()%(n);
        cout<<x<<" ";
		arr[j++]=x;
	}
    cout<<endl;
	find_k_smallest(arr,k,n);
	cout<<"k smallest number are:\n";
	sort(arr,arr+k);
	for(i=0;i<k;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}
