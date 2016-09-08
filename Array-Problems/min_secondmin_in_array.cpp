#include<iostream>
#include<cstdlib>
using namespace std;

void find_min(int *arr, int low, int high){
	if(high-low+1==1){
		cout<<"Min:"<<arr[low]<<endl;
		cout<<"No second min exist"<<endl;
	}
	else{
		int min,second_min;
		if(arr[low]<arr[low+1]){
			min=low;
			second_min=low+1;
		}
		else{
			min=low+1;
			second_min=low;
		}
		for(int i=low+2;i<=high;i++){
			if(arr[i]<arr[min]){
				second_min=min;
				min=i;
			}
			else if(arr[i]<arr[second_min] && arr[i]!=arr[min])
				second_min=i;
		}
		cout<<"Min: "<<arr[min]<<endl;
		cout<<"Second min: "<<arr[second_min]<<endl;
	}
}
int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		int x=rand()%n;
		cout<<x<<" ";
		arr[i]=x;
	}
	cout<<endl;
	find_min(arr, 0, n-1);
}
