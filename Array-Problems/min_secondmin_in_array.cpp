#include<iostream>
#include<cstdlib>
using namespace std;

void find_min(int *arr, int n){
	if(n==1){
		cout<<"Min:"<<arr[0]<<endl;
		cout<<"No second min exist"<<endl;
	}
	else{
		int min,second_min;
		if(arr[0]<arr[1]){
			min=0;
			second_min=1;
		}
		else{
			min=1;
			second_min=0;
		}
		for(int i=2;i<n;i++){
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
	find_min(arr, n);
}
