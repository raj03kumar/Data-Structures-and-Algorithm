//maximum subarray sum problem
//also known as kadane's algorithm
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int curr_sum=0;
    int max_sum=INT_MIN;
    for(int i=0;i<n;i++){
        curr_sum=max(0,curr_sum+=arr[i]); //if curr_sum<0 set curr_sum=0;
        max_sum=max(max_sum,curr_sum);
    }
    cout<<max_sum;
    return 0;
}

// Above one don't work for all negative values
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = -1e9, curr = 0;
        for(int i : nums) {
            curr += i;
            ans = max(ans, curr);
            if(curr < 0) curr = 0;
        }
        return ans;
    }
};
