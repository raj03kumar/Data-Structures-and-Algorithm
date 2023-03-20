/*
Q. There are N friends numbered from 0 to N-1. You have to choose 2 person such that they are not related to each other. You are given information in the form of M pairs(X,Y) i.e. there is a link between friend X and Y. Find out the number of ways in which 2 person from different groups can be choosen?
*/
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
    
    long long ans = 0;
    for(auto i: components){
        ans+=i*(n-i); //applying permutations and combinations.
    }
    cout<<ans/2; //to avoid overcounting like 2 3 and 3 2 are same.
    return 0;
}

/*
INPUT:
5 3
0 1
2 3
0 4
OUTPUT:
6
*/