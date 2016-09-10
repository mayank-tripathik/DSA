#include <iostream>
#include<cmath>
#include<cstdlib>
using namespace std;

int expo(int x,int n){
	int result=1;
	while(n>0){
		int exponent=n%10;
		int temp=pow(x,exponent);
		result=result*temp;
		x=pow(x,10);
		n=n/10;
	}
	return result;
}

int main() {
	int x,n;
	cin>>x;
	cin>>n;
	cout<<expo(x,n);
	return 0;
}
