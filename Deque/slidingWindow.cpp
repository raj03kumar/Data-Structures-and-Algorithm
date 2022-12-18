/*
basic O(n*k) approach:
for(i=0; i<n-k+1; i++){
    maxi=a[i];
    for(j=i; j<i+k; j++){
        maxi=max(a[j], maxi);
    }
    cout<<maxi<<" ";
}
*/

#include<bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int> &nums, int k ){
    deque<int> dq;
    vector<int> ans;
    for(int i=0; i<nums.size(); i++){
        //to remove out of bound. we know i is index and k is length of subarray.so we checck if the index fall into the subarray or not.
        if(!dq.empty() && dq.front()==i-k) dq.pop_front();  
        //for storing the elements in decreasing fashion.
        while(!dq.empty() && nums[dq.back()]<nums[i]){ //also we can take < or <= same.
            dq.pop_back();
        }
        dq.push_back(i);
        //now we push all the front elements to our ans vector.
        if(i>=k-1) ans.push_back(nums[dq.front()]);
    }
    return ans;
}

int main(){
    vector<int> nums={4,1,3,5,1,2,3,2,1,1,5};
    nums=maxSlidingWindow(nums,3);
    for(auto i: nums){
        cout<<i<<" ";
    }
    // the ans of sliding window maximum is 4,5,5,5,3,3,3,2,5
    return 0;
}