#include<bits/stdc++.h>
using namespace std;

int n, m; 
vector<bool> vis;
vector<vector<int>> adj;
vector<int> components;

int get_comp(int idx){
    if(vis[idx]) return 0;
    vis[idx]=true;
    int ans=1;
    for(auto i: adj[idx]){
        if(!vis[i]){
            ans+=get_comp(i);
            vis[i]=true;
        }
    }
    return ans;
}

int main(){
    cin>>n>>m;
    adj = vector<vector<int>>(n);
    vis = vector<bool>(n);
    for(int i=0; i<m; i++){
        int u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i=0; i<n; i++){
        if(!vis[i]) components.push_back(get_comp(i));
    }
    for(auto i: components){
        cout<<i<<" ";
    }
    return 0;
}

/*
INPUT:
5 3
0 1
2 3
0 4
OUTPUT:
3 2 
*/