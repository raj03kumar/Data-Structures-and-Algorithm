#include<bits/stdc++.h>
using namespace std;



int main(){
    int n; cin>>n;
    int target; cin>>target;
    vector <int> a(n);
    for(auto &i: a){
        cin>>i;
    }
    bool found=false;
    sort(a.begin(), a.end());
    for(int i=0; i<n; i++){
        //below is the code for two sum problem. 2 sum is also using 2 pointers low and high.
        int low=i+1; int high=n-1;
        while(low<high){
            int current=a[i]+a[low]+a[high];
            if(current==target){
                found=true;
            }
            if(current<target){
                low++;
            }
            else{
                high--;
            }
        }
    }
    if(found){
        cout<<"True";
    }
    else{
        cout<<"False";
    }

    return 0;

}