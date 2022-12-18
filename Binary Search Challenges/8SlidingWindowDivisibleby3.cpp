#include<bits/stdc++.h>
using namespace std;

void computeNumberFromSubarray(vector<int> arr, int k){
    pair<int, int> ans;
    int sum=0;
    //sliding window for first k elements
    for(int i=0; i<k; i++){
        sum+=arr[i];
    }
    bool found=false;
    if(sum%3==0){
        ans=make_pair(0, k-1);
        found=true;
    }

    for(int j=k; j<arr.size(); j++){
        if(found){
            break;
        }

        sum=sum+arr[j]-arr[j-k];
        if(sum%3==0){
            ans=make_pair(j-k+1, j);
            found=true;
        }
    }

    //if we didn't got the answer
    if(!found){
        ans=make_pair(-1, 0);
    }
    if(ans.first==-1){
        cout<<"No such subarray exist\n";
    }
    else{
        //we print the elements
        for(int i=ans.first; i<=ans.second; i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
    }
}

int main(){
    vector<int> arr={84, 23, 45, 12, 56, 82};
    int k=3;

    computeNumberFromSubarray(arr, k);
    return 0;
}   