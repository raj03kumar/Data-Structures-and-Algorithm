#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(int n){
    //just reverse the number and check if both are equal or not.
    string a = to_string(n);
    string b = to_string(n);
    reverse(a.begin(), a.end());
    if(a==b){
        return true;
    }
    else{
        return false;
    }
}

int findPalindromicSubArray(vector<int> arr, int k){
    int num=0; 

    for(int i=0; i<k; i++){
        num=num*10+arr[i];
    }
    //now we check if our ans is in first subarray or not.
    if(isPalindrome(num)){
        return 0;
    }

    //now for rest of the elements
    for(int j=k; j<arr.size(); j++){
        num=(num%(int)pow(10, k-1))*10+arr[j];

        //now we check for this subarray
        if(isPalindrome(num)){
            return j-k+1;
        }
    }

    return -1;
}

int main(){
    vector<int> arr={2,3,5,1,1,5};
    int k=4;

    int ans=findPalindromicSubArray(arr, k);

    if(ans==-1){
        cout<<"Palindromic subarray doesn't exist\n";
    }
    else{
        for(int i=ans; i<ans+k; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    //ans is 5 1 1 5
    return 0;
}