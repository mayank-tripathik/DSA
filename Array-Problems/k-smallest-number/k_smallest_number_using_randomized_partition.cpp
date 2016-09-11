
/*------------------This algorithm finds k smallest elements in array---------------*/
/*-----------------Time complexity: O(n) in worst case, O(n) on average--------------------------*/


#include<iostream>
#include<vector>
#include<cstdlib>
#include<algorithm>
using namespace std;

void printarray(int *arr, int k,int n){
    cout<<"Array:\n";
    for(int i=0;i<k;i++)
        cout<<arr[i]<<" ";
    cout<<"  ";
    for(int i=k;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
int pick_pivot(int l,int r){
    return (rand()%(r-l)+l);
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


void find_k_smallest(int *arr,int k, int n){
    if(2*k>n){
        sort(arr,arr+n);
    }
    else
    {
        int j,i,high,pivot,pos;
        high=2*k-1;
        pivot=pick_pivot(0,high);
        swap(arr[0],arr[pivot]);
        pivot=arr[0];
        printarray(arr,k,n);
        cout<<"pivot chosen:"<<arr[0]<<endl;
        pos=partition(arr,0,high,pivot);
        cout<<"pos:"<<pos<<endl;
        printarray(arr,k,n);
        j=2*k;
        while(j<n)
        {
            if(pos>=k-1){
                i=pos+1;
                while(i<2*k){
                    arr[i]=arr[j];
                    i++;
                    j++;
                    if(j>=n)
                        break;
                }
                high=i-1;
            }
            printarray(arr,k,n);
            cout<<"high:"<<high<<endl;
            pivot=pick_pivot(0,high);
            cout<<"pivot chosen index:"<<pivot<<endl;
            swap(arr[0],arr[pivot]);
            pivot=arr[0];
            cout<<"pivot chosen:"<<arr[0]<<endl;
            pos=partition(arr,0,high,pivot);
            cout<<"pos:"<<pos<<endl;
            printarray(arr,k,n);
            
        }
        while(pos!=k-1){
            cout<<"high:"<<endl;
            cout<<"trying:"<<endl;
            pivot=pick_pivot(0,high);
            cout<<"pivot chosen:"<<arr[0]<<endl;
            pos=partition(arr,0,high,pivot);
            cout<<"pos:"<<pos<<endl;
            printarray(arr,k,n);
        }
    }
}

int main(){
	int n,k,i,j;
	cin>>n;
    cin>>k;
	int arr[n];
    j=0;
	for(i=0;i<n;i++){
		//int x=rand()%(n);
        //cout<<i<<" ";
		cin>>arr[j++];
	}
    cout<<endl;
	find_k_smallest(arr,k,n);
	cout<<"k smallest number are:\n";
	sort(arr,arr+k);
	for(i=0;i<k;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}
