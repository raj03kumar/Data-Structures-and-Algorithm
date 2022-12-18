#include<bits/stdc++.h>
using namespace std;

int main(){
    //this is for n distinct elements.
    vector<vector<int>>ans;
    cout<<"Enter the number of elements: ";
    int n; cin>>n;
    vector<int> a(n); //creates a vector of size n;
    for(auto &i: a){
        cin>>i;
    }
    sort(a.begin(), a.end());
    do{
        ans.push_back(a);
    }while(next_permutation(a.begin(), a.end()));
    for(auto v:ans){
        for(auto i: v){
            cout<<i<<" ";
        }
        cout<<"\n";
    }
    return 0;
}