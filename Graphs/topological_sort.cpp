#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m; cin>>n>>m;
    int cnt=0;
    vector<vector<int>> adj_list(n);
    vector<int> indeg(n,0);
    for(int i=0; i<m; i++){
        int u, v; cin>>u>>v;
        // u-->v
        adj_list[u].push_back(v);
        indeg[v]++;
    }
    queue<int>pq;
    for(int i=0; i<n; i++){
        if(indeg[i]==0){
            pq.push(i);
        }
    }
    while(!pq.empty()){
        cnt++;
        int x=pq.front();
        pq.pop();
        cout<<x<<" ";
        // x-->v
        for(auto it: adj_list[x]){
            indeg[it]--;
            if(indeg[it]==0) pq.push(it);
        }
    }
    return 0;
}

/*
INPUT:
4 3
0 1
1 2
2 3
OUTPUT:
0 1 2 3

INPUT:
3 3
0 1
1 2
2 0
OUTPUT: nothing --> can be used to detect cycle in a graph
*/