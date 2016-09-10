
/* 
 * In this program, fibonacci modulo k of very large n (has 10^6 digits) is found using matrix method 
 * Matrix power is calculated using power of 10 method
 * n is stored as decimal number in array
 * Complexity : O((logn))
 */
 

#include <iostream>
#include<cstdlib>
using namespace std;

int A[2][2]={{1,1},{1,0}};
int result[2][2]={{1,0},{0,1}};
int msb,lsb;
long m;

void matrix_multiply(int M1[][2], int M2[][2])
{
    int temp[2][2];
    temp[0][0] = M1[0][0] * M2[0][0] + M1[0][1] * M2[1][0];
    temp[0][1] = M1[0][0] * M2[0][1] + M1[0][1] * M2[1][1];
    temp[1][0] = M1[1][0] * M2[0][0] + M1[1][1] * M2[1][0];
    temp[1][1] = M1[1][0] * M2[0][1] + M1[1][1] * M2[1][1];
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            M1[i][j] = temp[i][j] % m;
}

void divide_by_10(){
	lsb--;
}

bool num_greater_zero(){
	if(msb<=lsb)
        return true;
    else
        return false;
}


void matrix_power(int M[][2], int x) 
{
    int identity[2][2] = { { 1, 0 }, { 0, 1 } };
    while (x != 0) {
        if (x % 2 != 0) {
            matrix_multiply(identity, M);
        }
        matrix_multiply(M, M);
        x = x / 2;
    }
    for (int i = 0; i < 2; ++i)
        for (int j = 0; j < 2; ++j)
            M[i][j] = identity[i][j];
}


int fib(int *num){
	while (num_greater_zero()) {
        int temp[2][2];
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j)
                temp[i][j] = A[i][j];
        int exponent=num[lsb];
        matrix_power(temp,exponent);
        matrix_multiply(result, temp);
        matrix_power(A, 10);
        divide_by_10();
    }
    return result[1][0];
}

int main() {
	long num_of_digits;
	cin>>num_of_digits;            
	cin>>m;
	int num[num_of_digits];
    msb=0;
    lsb=num_of_digits-1;
    srand(time(NULL));
	for(int i=0;i<num_of_digits;i++){
		int x=rand()%10;
        //cout<<x<<" ";
		num[i]=x;
	}
    while(num[msb]==0)
        msb++;
	cout<<fib(num);
	return 0;
}
