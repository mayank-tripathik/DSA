#include<iostream>
#include<climits>
#include<cstdlib>
using namespace std;

int find_max(int *arr, int i , int j ){
	int max=i;
	for(int k=i+1;k<=j;k++){
		if(arr[k]>arr[max])
			max=k;
	}
	return max;
}
int max_diff_atmost_l(int *arr, int l, int n){
	int current_diff,pmin,pmax;
	int min=0;
	int max=find_max(arr,0,l);
	cout<<"Max:"<<arr[max]<<" and Min:"<<arr[min]<<endl;
	int diff=arr[max]-arr[min];
	cout<<"Difference:"<<diff<<endl;
	int second_max=INT_MIN;
	int second_max_index;
	for(int i=l+1;i<n;i++){
		min++;
        cout<<"min_pointer"<<min<<endl;
        cout<<"max_pointer"<<i<<endl;
		if(i-max>l){
            if(arr[i]>arr[second_max_index])
                   max=i;
			else
                max=second_max_index;
            second_max=INT_MIN;
		}
		else{
            if(arr[i]>arr[max])
                   max=i;
			else if(arr[i]>second_max){
				second_max=arr[i];
				second_max_index=i;
			}
		}
        cout<<"second_max"<<second_max<<endl;
		cout<<"Max:"<<arr[max]<<" and Min:"<<arr[min]<<endl;
		if(arr[max]-arr[min]>diff){
            pmin=max;
            pmax=min;
            diff=arr[max]-arr[min];
        }
		cout<<"Difference:"<<diff<<endl;
	}
	for(int i=min+1;i<=max;i++){
		cout<<"Max:"<<arr[max]<<" and Min:"<<arr[i]<<endl;
		if(arr[max]-arr[i]>diff){
            pmax=max;
            pmin=i;
            diff=arr[max]-arr[i];
        }	
		cout<<"Difference:"<<diff<<endl;
	}
    cout<<"pmin :"<<arr[pmin]<<" pmax : "<<arr[pmax]<<endl;
	return diff;
}

int main(){
	int n,l;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
        //int x=(rand()%n)-i;
        //cout<<x<<" ";
		cin>>arr[i];
	}
    cout<<endl;
	cin>>l;
	cout<<"answer:"<<max_diff_atmost_l(arr,l,n)<<endl;
}
