/*
 * Input n is in the form of decimal, stored in array
 * Input is converted into binary, then fibonacci is calculated
 * Fibonacci mudulo k is calculated using matrix approach
 * n can have 10^6 digits i.e n=10^10^6
 * squared exponentiation is used for matrix power
 * Complexity: O((logn)^2)
 */
 
 
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int dmsb,dlsb,bmsb,blsb;

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

void initialize_index(int n, int *dnum){
    dmsb=0;
    while(dnum[dmsb]==0)
        dmsb++;
    dlsb=n-1;
    bmsb=4*n-1;
    blsb=4*n-1;
}

bool decimal_division_by_two(int *dnum){
    int carry=0;
    for(int i=dmsb;i<=dlsb;i++){
        int next_digit=dnum[i]+carry;
        dnum[i]=next_digit/2;
        if(next_digit&1)
            carry=10;
        else
            carry=0;
    }
    while(dnum[dmsb]==0)
        dmsb++;
    if(carry==0)
        return false;
    else
        return true;
}

void decimal_to_binary(int *dnum, int *bnum){
    while(dmsb<=dlsb){
        bool carry_generated=decimal_division_by_two(dnum);
        if(carry_generated)
            bnum[bmsb]=1;
        else
            bnum[bmsb]=0;
        bmsb--;
    }
    bmsb++;
}

bool binary_num_greater_than_zero(){
    if(bmsb<=blsb)
        return true;
    else
        return false;
}

bool binary_number_is_odd(int *bnum){
    if(bnum[blsb]==1)
        return true;
    else
        return false;
}

void binary_division_by_two(){
    blsb--;
}

void matrix_power(int *bnum,long m){
    while(binary_num_greater_than_zero()){
        if(binary_number_is_odd(bnum))
            matrix_multiply(result,A,m);
        matrix_multiply(A,A,m);
        binary_division_by_two();
        }
}


int fib(int *bnum, long m){
    matrix_power(bnum,m);
    return result[1][0];
}

int main() {
    long n;  //length of the number of whose fibonacci is to be calculated
    long m;
    cin>>n;
    int dnum[n];
    int bnum[4*n];
    cin>>m;
    srand(time(NULL));
    for(int i=0;i<n;i++){
        int x=rand()%10;
        dnum[i]=x;
        //cout<<dnum[i]<<" ";
    }
    initialize_index(n,dnum);
    decimal_to_binary(dnum,bnum);
    /*for(int i=bmsb;i<=blsb;i++)
        cout<<bnum[i]<<" ";*/
    //cout<<endl;
    cout<<fib(bnum,m);
    return 0;
}
