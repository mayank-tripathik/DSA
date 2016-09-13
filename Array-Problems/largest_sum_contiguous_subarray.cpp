/*
 * Problem : To find the sum of contiguous subarray within a one-dimensional array of numbers which has the largest sum 
 * Kadane's Algorithm
 * Time Complexity: O(n)
 * Following Implimentation works for all negative numbers too
 */


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int max_sum_contiguous(int *arr, int n){
    int max_sum=arr[0],current_sum=arr[0];
    for(int i=1;i<n;i++){
        current_sum=max(arr[i],current_sum+arr[i]);
        max_sum=max(current_sum,max_sum);
    }
    return max_sum;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<max_sum_contiguous(arr,n)<<endl;
}
