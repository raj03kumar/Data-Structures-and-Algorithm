/*Question: Given an array unsorted, but you have sorted it now. [1,2,5,7,11,12] and you are given k=3. means you have to find 3 elements who's difference among themselves is maximum. 
We have to find 3 elements so let them be a, b, c. so for the difference a-b and b-c should be maximum.
so the range of differences are from 1 to 12. because the left element is 1 and the right element is 12.
so the mid becomes 6.
so if we search for 6 then we get 1 and 7 and there difference is 6 but on the other hand side we dont have 13. so the 6 can't be the maximimum distance between them.
so we now have left=1 and right =6.
so now the mid is 3.
so we get (1,5,11) and atleast minimum distance between them is 3 or more than 3.
so 3 is a valid answer so we update left with 3.
so now we have left=3 and right=6. so the mid is 4.
so again we get (1,5,11) so 4 is feasible. so new
left=4 and right =6. so the new mid is 5.
so we get (1,7,12) which is the solution. because they have atleast distance of 5 between each one of them.
*/
#include<bits/stdc++.h>
using namespace std;

bool isFeasible(int mid, int arr[], int n, int k){
    int pos=arr[0], elements=1;

    for(int i=1; i<n; i++){
        if(arr[i]-pos>=mid){
            pos=arr[i];
            elements++;
            if(elements==k){
                return true;
            }
        }
    }

    return false;
}

int largestMinDistance(int arr[], int n, int k){
    //we sort the array.
    sort(arr, arr+n);

    int result=-1;
    //now we define left and right.
    int left=1, right=arr[n-1];
    while(left<right){
        int mid=(left+right)/2;
        if(isFeasible(mid, arr, n, k)){
            result=max(result, mid);
            left=mid+1;
        }
        else{
            right=mid;//means we search in the right subarray.
        }
    }

    return result;
}

int main(){
    int arr[]={1,2,8,4,9};
    int n=5;    //size of the array.
    int k=3;

    cout<<"Largest min distance is: "<<largestMinDistance(arr, n, k);

    //ans we can choose 1 then 4 then we can choose either 8 or 9.
    return 0;
}