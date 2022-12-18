#include<bits/stdc++.h>
using namespace std;

int smallestSubarrayWithSum(int arr[], int n, int x){
    int sum=0, minLength=n+1, start=0, end=0;
    while(end<n){
        while(sum<=x and end<n){
            sum+=arr[end++];
        }

        while(sum>x and start<n){
            if(end-start<minLength){
                minLength=end-start;
            }
            sum-=arr[start++];
        }
    }
    return minLength;   
}

int main(){
    int arr[]={1,4,45, 6, 10,19};
    int x=51;
    int n=6;
    
    int minLength=smallestSubarrayWithSum(arr, n, x);
    if(minLength==n+1){
        cout<<"No such subarray exist\n";
    }
    else{
        cout<<"smallest length subarray is: "<<minLength;
    }
    //note: we are looking for subarray greater than x and not even equal to X. so we have ans as 3.

    return 0;
}   