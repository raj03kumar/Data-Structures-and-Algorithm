/*
we have to find longest subarray which contains atmost k 0s.

so to find this we have to do:
for each A[j], try to find longest subarray.
- If A[i] to A[j] has zeros <=K, then there is no problem, we can expand our array.
- If A[i] to A[j] has zeros >k, then we have to shrink our array.(we increment i as well as j)


PSEUDO CODE:
int zeroCount=0, i=0, ans=0;
for(int j=0; j<A.size(); j++){
    if(A[j]==0){
        zeroCount++;
    }
    while(zeroCount>K){
        if(A[i]==0){        //we remove this element(A[i]) from our subarray.
            zeroCount--;
        }
        i++;
    }
    ans=max(ans, j-1+1);
}
*/
/*
a[i.....j] is our window
a[i.......j+1] means we are increasing or expanding our window.
a[i+1....j] means we are shrinking our window.
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    cout<<"Enter the value of n: ";
    int n; cin>>n;
    cout<<"Enter the value of k: ";
    int k; cin>>k;
    vector<int> a(n);
    cout<<"Enter the values of array: ";
    for(auto &i: a){
        cin>>i;
    }
    int zeroCount=0, i=0, ans=0;
    for(int j=0; j<n; j++){
        if(a[j]==0){
            zeroCount++;
        }
        //now we have to check our condition if zero count is not greater than k. if yes, then we have to shrink our array.
        while(zeroCount>k){
            if(a[i]==0){
                zeroCount--;
            }
            i++;    //by this we increase the value of i and shrink our array.
        }
        //after it comes out of while loop then it is already zeroCount <=k, so we update our ans
        ans=max(ans, j-i+1);
    }
    cout<<ans;
    return 0;
}