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
	else if(n%2!=0){
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



/* ------------ Iterative approach (Faster and recommended)----------------*/

#include <iostream>
using namespace std;
int power(int x, int n){
	int result=1;
	while(n>0){
		if(n&1)    //checking if number is odd
			result=result*x;
		x=x*x;
		n=n>>1;    //dividing n by 2 using faster shift operation
	}
	return result;
}
int main() {
	int x,n;
	cin>>x;
	cin>>n;
	cout<<power(x,n)<<endl;
	return 0;
}
