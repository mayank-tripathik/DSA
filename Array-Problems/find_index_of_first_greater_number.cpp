/*
 * Time Complexity: O(2n) Amortized
 */

#include <iostream>
#include<stack>
using namespace std;

void first_number_greater(int *arr, int *pi, int n){
	stack<int> mystack;
	mystack.push(0);
	for(int i=1;i<n;i++){
		while(!mystack.empty() && arr[i]>arr[mystack.top()]){
			pi[mystack.top()]=i;
			mystack.pop();
		}
		mystack.push(i);
	}
	while(!mystack.empty()){
		pi[mystack.top()]=0;
		mystack.pop();
	}
		
}
int main() {
	int n;
	cin>>n;
	int arr[n];
	int pi[n];
	for(int i;i<n;i++)
		cin>>arr[i];
	first_number_greater(arr,pi,n);
	for(int i;i<n;i++)
		cout<<pi[i]<<endl;
	return 0;
}
