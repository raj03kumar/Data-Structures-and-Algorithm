#include<bits/stdc++.h>
using namespace std;

bool isNumberPerfect(int n){
    int sum=1;  //because 1 is the factor of all the numbers

    for(int i=2; i*i<=n; i++){
        if(n%i==0){
            if(i==n/i){
                sum+=i;
            }
            else{
                sum+=i+n/i;
            }
        }
    }

    //now we check the sum and whether n is not 1 because 1 is not a perfect number
    if(sum==n and n!=1){
        return true;
    }
    return false;
}

int maxSum(int arr[], int n, int k){
    if(n<k){
        cout<<"Inavalid values\n";
        return -1;
    }
    //now we apply sliding window.
    int res=0;
    for(int i=0; i<k; i++){
        res+=arr[i];
    }

    int sum=res;
    for(int i=k; i<n; i++){
        sum+=arr[i]-arr[i-k];
        res=max(res, sum);
    }
    return res;
}

int maxNumberOfPerfects(int arr[], int n, int k){
    for(int i=0; i<n; i++){
        if(isNumberPerfect(arr[i])){
            arr[i]=1;
        }
        else{
            arr[i]=0;
        }
    }
    //now this problem reduces to find the maximum sum of the binary subarray.

    return maxSum(arr, n, k);
}

int main(){
    int arr[]={28, 2, 3, 6, 496, 99, 8128, 24};
    int k=4;
    int n=8;

    cout<<maxNumberOfPerfects(arr, n, k);
    //ans is 3. 
    return 0;
}