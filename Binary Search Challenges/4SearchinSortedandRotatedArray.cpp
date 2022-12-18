#include<bits/stdc++.h>
using namespace std;

int searchInRotatedArray(int arr[], int key, int left, int right){
    if(left>right){
        return -1;
    }
    int mid=(left+right)/2;
    if(arr[mid]==key){
        return mid;
    }
    if(arr[left]<=arr[mid]){
        if(key>=arr[left] and key <=arr[mid]){
            return searchInRotatedArray(arr, key, left, mid-1);
        }
        return searchInRotatedArray(arr, key, mid+1, right);
    }

    if(key>=arr[mid] and key<=arr[right]){
        //search in right subarray.
        return searchInRotatedArray(arr, key, mid+1, right);
    }
    //search in left subarray.
    return searchInRotatedArray(arr, key, left, mid-1);
}

int main(){
    int arr[]= {6,7,8,9,10,1,2, 3,4,5};     //here the pivot is 10.
    int n=10;
    int key=5;

    int idx=searchInRotatedArray(arr, key, 0, n-1);

    if(idx==-1){
        cout<<"Key doesn't exist\n";
    }
    else{
        cout<<"Key is present at index: "<<idx<<"\n";
    }
    return 0;
}