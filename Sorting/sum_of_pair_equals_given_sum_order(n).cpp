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
