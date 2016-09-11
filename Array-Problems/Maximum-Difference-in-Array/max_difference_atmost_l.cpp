#include<iostream>
using namespace std;
int main(){
	int n,l;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	cin>>l;
	int i = 0, max = a[1] - a[0];
	for(int j = 1; j < n; j++)
	{
		if((a[j] - a[i]) > max){
			max = a[j] - a[i];
		}
		if(a[j] < a[i]){
			i = j;
		}
		if(i < j - l + 1){
			i = j - l + 1;
		}
	}
	cout<<max;
}
