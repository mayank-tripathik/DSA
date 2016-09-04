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
		cout<<"Candiadate is : "<<bucket<<endl;
		count=0;
		for(j=0;j<n;j++){
			if(arr[j]==bucket)
				count++;
			}
		if(count>(n/2)){
			cout<<"Majority ELements is : "<<bucket<<endl;
		}
		else
			cout<<"No majority element exists!\n";
		}
	}






/*--------------Time complexity : O(n)-----------*/
/*----Majority of an element here is considered as that element that is repeated atleast n/3 times --------*/


#include<iostream>
using namespace std;
int main(){
	int test;
	cin>>test;
	while(test--){
		int n,bucket1,bucket2,count1=0,count2=0,j;
		cin>>n;
		int arr[n];
		for(j=0;j<n;j++)
			cin>>arr[j];
		for(j=0;j<n;j++)
		{
			if(count1==0 || bucket1==arr[j] )
			{
				bucket1=arr[j];
				count1++;
			}
			else if(count2==0 || bucket2==arr[j] )
			{
				bucket2=arr[j];
				count2++;	
			}
			else if(bucket1!=arr[j] && bucket2!=arr[j])
			{
				count1--;
				count2--;
			}
		}
		cout<<"Candiadates are "<<bucket1<<" and "<<bucket2<<endl;
		count1=0;
		count2=0;
		for(j=0;j<n;j++){
			if(arr[j]==bucket1)
				count1++;
			else if(arr[j]==bucket2)
				count2++;
			}
		if(count1>(n/3) || count2>(n/3)){
			cout<<"Majority ELements is/are :";
			if(count1>(n/3))
				cout<<bucket1<<" ";
			if(count2>(n/3))
				cout<<bucket2<<endl;
		}
		else{
			cout<<"No majority element exist!\n";
		}
	}
}
