#include<bits/stdc++.h>
using namespace std;

int findPeakElement(int arr[], int low, int high, int n){
    int mid=low+(high-low)/2; //it is same as what you are thinking. Sometimes high+low excedes the integer limit so for safety we use that.

    if((mid==0 or arr[mid-1]<=arr[mid])and(mid==n-1 or arr[mid+1]<=arr[mid])){
        //this is for the corner case.
        return mid;
    }
    else if(mid>0 and arr[mid-1]>arr[mid]){
        //for left half
        return findPeakElement(arr, low, mid-1, n);
    }
    else{
        return findPeakElement(arr, mid+1, high, n);
    }
}

int main(){
    int arr[]={0,6,8,5,7,9};
    //sort(arr, arr+6);
    int n=6;
    cout<<"Peak element index: "<<findPeakElement(arr, 0, n-1, n)<<endl;
    return 0;
}