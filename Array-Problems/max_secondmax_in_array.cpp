#include<iostream>
#include<cstdlib>
using namespace std;

void find_max(int *arr, int n){
	if(n==1){
		cout<<"Max:"<<arr[0]<<endl;
		cout<<"No second max exist"<<endl;
	}
	else{
		int max,second_max;
		if(arr[0]>arr[1]){
			max=0;
			second_max=1;
		}
		else{
			max=1;
			second_max=0;
		}
		for(int i=2;i<n;i++){
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
	find_max(arr, n);
}
