/*--------------Time complexity : O(n)-----------*/
/*----Majority of an element here is considered as that element that is repeated atleast n/2 times --------*/
#include<iostream>
using namespace std;
int main(){
	int test;
	cin>>test;
	while(test--){
		int n,bucket,count=1,j;
		cin>>n;
		int arr[n];
		for(j=0;j<n;j++)
			cin>>arr[j];
		bucket=arr[0];
		for(j=0;j<n;j++){
			if(bucket==arr[j])
				count++;
			else{
				count--;
			}
			if(count==0)
			{
				bucket=arr[j];
				count=1;
			}
				
		}
		cout<<bucket;
		}
	}
