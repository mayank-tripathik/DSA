#include<iostream>
#include<cstdlib>
using namespace std;

void find_max(int *arr, int low, int high){
	if(high-low+1==1){
		cout<<"Max:"<<arr[low]<<endl;
		cout<<"No second max exist"<<endl;
	}
	else{
		int max,second_max;
		if(arr[low]>arr[low+1]){
			max=low;
			second_max=low+1;
		}
		else{
			max=low+1;
			second_max=low;
		}
		for(int i=low+2;i<=high;i++){
			if(arr[i]>arr[max]){
				second_max=max;
				max=i;
			}
			else if(arr[i]>arr[second_max] && arr[i]!=arr[max])
				second_max=i;
		}
		cout<<"Max: "<<arr[max]<<endl;
		cout<<"Second max: "<<arr[second_max]<<endl;
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
	find_max(arr, 0, n-1);
}
