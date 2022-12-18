/*
let us assume that there are 4 books with pages [12, 34, 67, 90] and we have to give these books to 2 students. 
so 1. we give 1st book to 1st student and give other three to 2nd student.
i.e. [12],[34, 67, 90] --> 191 is the maximum pages alloted to the second child.
or 2. we give 1st and second book to 1st student and 3rd and 4th book to the 2nd student.
i.e. [12, 34], [67, 90]--> 157 is the maximum pages alloted to the second child.
or 3. we give the first three books to the first student and we give the last book to the second student.
i.e. [12, 34, 67], [90] --> 113 is the maximum pages alloted to the first child so we have 113 as our answer.
*/

#include<bits/stdc++.h>
using namespace std;

bool isPossible(int arr[], int n , int m, int min){
    int studentsRequired=1, sum=0;
    for(int i=0; i<n; i++){
        if(arr[i]>min){
            return false;
        }
        //when we have to move to different student because we have allocated many books to this particualr student then
        if(sum+arr[i]>min){
            studentsRequired++;
            sum=arr[i];

            if(studentsRequired>m){
                return false;
            }
        }
        else{
            //when we can still allocate books to same student.
            sum+=arr[i];
        }
    }
    return true;
}

//to find the minimum number of pages
int allocateMinimumPages(int arr[], int n, int m){
    int sum=0;
    if(n<m){
        return -1;
    }

    for(int i=0; i<n; i++){
        sum+=arr[i];
    }
    //now we start our binary search. NOTE: this is binary search.
    //first we allocate all the books to one student. which will be the max no. of pages
    int start=0, end=sum, ans=INT_MAX;
    while(start<=end){
        int mid=(start+end)/2;
        if(isPossible(arr, n, m, mid)){
            //we make a function to check if the mid element is feasible or not.
            ans=min(ans, mid);
            end=mid-1;
        }
        else{
            start=mid+1;
        }
    }

    return ans;
}

int main(){
    int arr[]={12, 34, 67, 90};
    int n=4; //no of books
    int m=2;
    cout<<"minimum number of pages: "<<allocateMinimumPages(arr, n,m);
    return 0;
}   