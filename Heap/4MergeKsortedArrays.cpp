#include<bits/stdc++.h>
using namespace std;
/*
    input:
    3
    3
    1 4 6
    2
    2 3
    3
    5 6 7

    output: 1 2 3 4 5 6 6 7
*/

int main(){
    int n; cin>>n;
    vector<vector<int>> a(n);

    for(int i=0; i<n; i++){
        int size; cin>>size;

        a[i]=vector<int>(size);
        for(int j=0;j<size; j++){
            cin>>a[i][j];
        }
    }
    vector<int> idx(n,0);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
    for(int i=0; i<n; i++){
        pq.push({a[i][0], i});
    }
    vector<int>ans;

    while(!pq.empty()){
        pair<int, int> x=pq.top();
        pq.pop();

        ans.push_back(x.first);

        if(idx[x.second]+1<a[x.second].size()){
            pq.push({a[x.second][idx[x.second]+1], x.second});
        }
        idx[x.second]++;
    }

    //now we have done our merging of k different sorted array. now we print them
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }

    return 0;
}   