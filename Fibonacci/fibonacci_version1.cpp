/* 
 * In this program, fibonacci modulo k of very large n (has 10^6 digits) is found using matrix method 
 * Matrix power is calculated using squared exponentiation that has O(logn) complexity
 * n is stored as decimal number in array
 * Complexity : O((logn)^2)
 */
 

#include <iostream>
#include<cstdlib>
using namespace std;

int A[2][2]={{1,1},{1,0}};
int result[2][2]={{1,0},{0,1}};

void matrix_multiply_result(long k){
	int temp[2][2];
	temp[0][0]=result[0][0]*A[0][0]+result[0][1]*A[1][0];
	temp[0][1]=result[0][0]*A[0][1]+result[0][1]*A[1][1];
	temp[1][0]=result[1][0]*A[0][0]+result[1][1]*A[1][0];
	temp[1][1]=result[1][0]*A[0][1]+result[1][1]*A[1][1];
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 2; ++j)
			result[i][j] = temp[i][j] % k;
}

void matrix_multiply_A(long k){
	int temp[2][2];
	temp[0][0]=A[0][0]*A[0][0]+A[0][1]*A[1][0];
	temp[0][1]=A[0][0]*A[0][1]+A[0][1]*A[1][1];
	temp[1][0]=A[1][0]*A[0][0]+A[1][1]*A[1][0];
	temp[1][1]=A[1][0]*A[0][1]+A[1][1]*A[1][1];
	for (int i = 0; i < 2; ++i)
		for (int j = 0; j < 2; ++j)
			A[i][j] = temp[i][j] % k;
}

void div_by_two(long *arr, long n){
	long carry=0;
	for(int i=0;i<n;i++){
		int next_digit=arr[i]+carry;
		arr[i]=next_digit/2;
		if(next_digit&1)
			carry=10;
		else
			carry=0;
	}
}

bool num_greater_zero(long *num, long n){
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

void matrix_power(long *num,long n,long k){
	while(num_greater_zero(num,n)){
		if(num[n-1]%2==1)
			matrix_multiply_result(k);
		matrix_multiply_A(k);
		div_by_two(num,n);
	}
}


int fib(long *num, long n,long k){
	matrix_power(num,n,k);
	return result[1][0];
}


int main() {
	long n,k;
	cin>>n;
	cin>>k;
	long num[n];
	for(int i=0;i<n;i++){
		int x=rand()%n;
		num[i]=x;
	}
	cout<<fib(num,n,k);
	return 0;
}
