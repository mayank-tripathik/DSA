/*
 * This program calcualtes fibonacci of a large number modulo m
 * This approach uses the concept of pisano period
 * Pisano period is the period with which the sequence of Fibonacci numbers taken modulo m repeats
 * Memory of fibonacci numbers that are post pisano period is maintained
 * Modulo period of such large n gives the desired index where fib(n) is stored in mem
 * Complexity: O(log n)
 */



#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void populate_mem(int *mem, int m){
    mem[0]=0;
    mem[1]=1;
    for(int i=2;i<=6*m;i++)
        mem[i]=(mem[i-1]+mem[i-2])%m;
}

int find_period(int *mem, int m){
    int period;
    for(int i=3;i<=6*m;i++){
        if(mem[i-1]==0 && mem[i]==1){
            period=i-1;
            break;
        }
    }
    return period;
}

int find_modulo(int *num, int n, int period){
    int carry=0,next_digit;
    for(int i=0;i<n;i++){
        next_digit=num[i]+carry;
        carry=(next_digit%period)*10;
    }
    return carry/10;
}

int fib(int *num, int n, int m){
    int mem[6*m+1];
    populate_mem(mem,m);
    /*for(int i=0;i<6*m;i++){
        cout<<mem[i]<<" ";
    }*/
    int period=find_period(mem,m);
    cout<<"Period for this k is :"<<period<<endl;
    int pos=find_modulo(num,n,period);
    return mem[pos];
}

int main() {
    long n;  //length of the number of whose fibonacci is to be calculated
    int num[n];
    long m;
    cin>>n;
    cin>>m;
    srand(time(NULL));
    for(int i=0;i<n;i++){
        int x=rand()%10;
        num[i]=x;
        //cout<<num[i]<<" ";
    }
    //cout<<endl;
    cout<<"Fib(n) % m is : "<<fib(num,n,m); 
    return 0;
}
