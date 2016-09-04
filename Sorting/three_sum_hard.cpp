/*-----------------------Time Complexity : O(nlogn)+O(n^2)=O(n^2)--------------------*/
// Note that this problem is generalised as 3SUM_HARD problem 
// and the question of whether there is a better than quadratic algorithm is open.


#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int n,i,l,r;
	cin>>n;
	int arr[n];
	for(i=0;i<n;i++) 
		cin>>arr[i];
	sort(arr,arr+n,greater<int>());
	for(i=0;i<n;i++){
		l=i+1;
		r=n-1;
		while(l<r){
			if(arr[l]+arr[r]==arr[i]){
				cout<<arr[l]<<"+"<<arr[r]<<"="<<arr[i]<<endl;
				break;
			}
			else if(arr[l]+arr[r]<arr[i])
				r--;
			else
				l++;
		}
	}
	return 0;
}
