/*--------Algo1 : O(n) Time complexity with O(n) space complexity using hashmap------------*/

#include<iostream>
#include<unordered_set>
using namespace std;
int main(){
	unordered_set<int> hashmap;
	int n,i,sum;
	cin>>n;
	int arr[n];
	for(i=0;i<n;i++) 
		cin>>arr[i];
	cin>>sum;
	hashmap.insert(arr[0]); //Inserting the first value in hashmap
	unordered_set<int>::const_iterator itr;
	for(i=1;i<n;i++){
		itr=hashmap.find(sum-arr[i]);
		if(itr!=hashmap.end()){  //Checking if subsequent array values sums up with other to provide given sum
			cout<<"Candidates are "<<(*itr)<<" and "<<arr[i]<<endl;
			break;
		}
		else
			hashmap.insert(arr[i]);
	}
		if(i==n)
			cout<<"False";
		else
			cout<<"True";
	return 0;
}


/*--------Algo2 : O(nlogn) Time complexity with O(1) space complexity using Sorting------------*/



#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int test;
	cin>>test;
	while(test){
		int n,x,i,j;
		cin>>n;
		int arr[n];
		cin>>x;
		for(i=0;i<n;i++)
			cin>>arr[i];
		sort(arr,arr+n);
		i=0;
		j=n-1;
		while(i<=j){
			if(arr[i]+arr[j]==x)
				break;
			else if(arr[i]+arr[j]>x)
				j--;
			else if(arr[i]+arr[j]<x)
				i++;
			}
		if(i>j)
			cout<<"False\n";
		else
			cout<<"True\n";
		}
}
