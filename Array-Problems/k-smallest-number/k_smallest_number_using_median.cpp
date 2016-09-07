/*---------------This algorithm finds kth largest element or (n-k+1)th smallest elment---------------*/
/*-----------This algorithms can also be seen as an algorithm for returning element whose rank is k ---------------*/
/*-----------------Time complexity: O(n) in worst case, O(n) on average--------------------------*/

#include<iostream>
#include<vector>
#include<cstdlib>
#include<algorithm>
using namespace std;

void printarray(int *arr,int k, int n){
	cout<<"Array:\n";
	/*for(int i=0;i<2*k;i++)
		cout<<arr[i]<<" ";
	cout<<"  ";
	for(int i=2*k;i<n;i++)
		cout<<arr[i]<<" ";*/
    for(int i=0;i<n;i++)
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

void find_k_smallest(int *arr,int k, int n){
    int pivot,j,pos,i;
    if(2*k>n){
        sort(arr,arr+n);
    }
    else
    {
        pivot=median_of_median(arr,0,2*k-1);
        //cout<<"Pivot picked : "<<arr[pivot]<<endl;
        swap(arr[0],arr[pivot]);
        //printarray(arr,k,n);
        pivot=arr[0];
        pos=partition(arr,0,2*k-1,pivot);
        //printarray(arr,k,n);
        //cout<<"Pivot's right place:"<<pos<<endl;
        j=2*k;
        //cout<<"j:"<<j<<endl;
        i=pos+1;
        while(j<n)
        {
            //cout<<"j:"<<j<<endl;
            //cout<<"i:"<<i<<endl;
            while(i<2*k)
            {
                arr[i]=arr[j];
                //printarray(arr,k,n);
                j++;
                i++;
                if(j>=n)
                    break;
            }
            pivot=median_of_median(arr,0,i-1);
            //cout<<"Pivot picked : "<<arr[pivot]<<endl;
            swap(arr[0],arr[pivot]);
            //printarray(arr,k,n);
            pivot=arr[0];
            pos=partition(arr,0,i-1,pivot);
            i=pos+1;
            //printarray(arr,k,n);
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
	for(i=0;i<k;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}
