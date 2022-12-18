#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    vector<vector<int>> v;
    for(int i=0; i<n; i++){
        int start, end;
        cin>>start>>end;
        v.push_back({start, end}); //{,} is used to push the vector into v.
    }
    sort(v.begin(), v.end(), [&](vector<int> &a, vector<int>&b){return a[1]<b[1];});
    //here [&]is the lamda function and it is making a comparator for sorting the time.
    int take=1;
    int end=v[0][1];
    for(int i=1; i<n; i++){
        if(v[i][0]>=end){
            take++;
            end=v[i][1];
        }
    }
    cout<<take<<"\n";
    return 0;

    /*
    INPUT:
    3
    10 20 
    12 15
    20 30
    OUTPUT:
    2
    */
}