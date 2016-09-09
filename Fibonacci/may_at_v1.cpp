#include <iostream>
using namespace std;

int a[][2]={(1,1),(1,1)};
bool greater_zero(int *num, int n){
	int i;
	for(i=0;i<n;i++){
		if(num[i]>0)
			break;
	}
	if(i==n)
		return 0;
	else
		return 1;
}

int main() {
	int n;
	cin>>n;
	int num[n];
	for(int i=0;i<n;i++)
		cin>>num[i];
	cout<<greater_zero(num,n);
	return 0;
}
