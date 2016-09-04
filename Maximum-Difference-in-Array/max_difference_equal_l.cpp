/*----------------------O(n) time complexity------------------*/
// Maintain maximum difference between two elements such that j is equal to i+l. Return maxdiff accordingly. 


#include<iostream>
using namespace std;
int main(){
	int test;
	cin>>test;
	while(test--){
		int n,difference,i,j,l;
		cin>>n;
		int arr[n];
		for(j=0;j<n;j++)
			cin>>arr[j];
		cin>>l;
		difference=arr[l]-arr[0];
		i=1;
		for(j=l+1;j<n;j++){
			if(arr[j]-arr[i]>difference)
				difference=arr[j]-arr[i];
			i++;
			}
		cout<<difference<<endl;
		}
	}
