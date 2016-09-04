/*-----------O(n) Time Complexity ------------*/

#include<iostream>
using namespace std;
int main(){
	int test;
	cin>>test;
	while(test--){
		int n,i,max,min;
		cin>>n;
		int arr[n];
		for(i=0;i<n;i++)
			cin>>arr[i];
		max=min=arr[0];
		for(i=1;i<n;i++){
			if(arr[i]>max)
				max=arr[i];
			else if(arr[i]<min)
				min=arr[i];
			}
		cout<<max-min<<endl;
		}
}
