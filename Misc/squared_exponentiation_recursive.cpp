/*
 * O(logn) Time complexity
 */


#include <iostream>
using namespace std;
int count=0;
int power(int x, int n){
	if(n==0)
		return 1;
	else if(n==1)
		return x;
	else if(n%2==0){
		count++;
		return power(x*x,n/2);
	}
		
	else{
		count=count+2;
		return (x*power(x*x,(n-1)/2));
	}
}
int main() {
	int x,n;
	cin>>x;
	cin>>n;
	cout<<power(x,n)<<endl;
	cout<<"number of multiplications:"<<count<<endl;
	return 0;
}
