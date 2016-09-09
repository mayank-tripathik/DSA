/*
 * Input n is in the form of binary, stored in array
 * Fibonacci mudulo k is calculated using matrix approach
 * n can have 10^6 digits i.e n=10^10^6
 * squared exponentiation is used for matrix power
 * Complexity: O(logn)
 */
 
 
#include <iostream>
#include<cstdlib>
using namespace std;
int dlsb,dmsb,blsb,bmsb;
int A[2][2]={{1,1},{1,0}};
int result[2][2]={{1,0},{0,1}};

void matrix_multiply(int M1[][2], int M2[][2], long k)
{
    int temp[2][2];
    temp[0][0] = M1[0][0] * M2[0][0] + M1[0][1] * M2[1][0];
    temp[0][1] = M1[0][0] * M2[0][1] + M1[0][1] * M2[1][1];
    temp[1][0] = M1[1][0] * M2[0][0] + M1[1][1] * M2[1][0];
    temp[1][1] = M1[1][0] * M2[0][1] + M1[1][1] * M2[1][1];
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            M1[i][j] = temp[i][j] % k;
}

void div_by_two(){
	blsb--;
}

bool num_greater_zero(char call){
	if(call=='d'){
		if (dmsb> dlsb|| num[dmsb] == 0)
			return 0;
		else
			return 1;
	}
	else{
		if (bmsb> blsb|| num[bmsb] == 0)
			return 0;
		else
			return 1;
		
	}
	
}

void matrix_power(long *num,long n,long k){
	while(num_greater_zero('b')){
		if(num[lsb]==1)
			matrix_multiply(result,A,k);
		matrix_multiply(A,A,k);
		div_by_two();
	}
}


int fib(long *bnum, long n,long k){
	matrix_power(bnum,n,k);
	return result[1][0];
}

void div_by_two_decimal{
	long carry=0;
	for(int i=0;i<n;i++){
		int next_digit=arr[i]+carry;
		arr[i]=next_digit/2;
		if(next_digit&1)
			carry=10;
		else
			carry=0;
	}
    while(arr[i]==0 && dmsb<=dlsb)
        dmsb++;
    if(carry==10)
        return 1;
    else
        return 0;
}

void decimal_to_binary(int *dnum, int *bnum, int n)
{
    while(greater_than_zero('d')){
        if(divide_by_two_decimal(dnum,n))
            bnum[bmsb]=1;
        else
            bnum[bmsb]=0;
        bmsb--;
        
    }
}

int main() {
	long n,k;
	cin>>n;
	cin>>k;
	long dnum[n];
    long bnum[n*4];
    dlsb=n-1;
    dmsb=0;
    blsb=n*4-1;
    bmsb=n*4-1;
	for(int i=0;i<n;i++){
		int x=rand()%n;
		dnum[i]=x;
	}
	while(dnum[dmsb]==0)
		dmsb++;
    decimal_to_binary(dnum,bnum,n);
	cout<<fib(bnum,n,k);
	return 0;
}
