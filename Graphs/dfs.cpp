// DEPTH FIRST SEARCH
#include<bits/stdc++.h>
using namespace std;

const int N=1e5+2;
bool vis[N];
vector<int> adj[N];

void dfs(int node){
    //preorder
    vis[node]=1;
    cout<<node<<" ";

    //inorder
    for(auto it: adj[node]){
        if(!vis[it]) dfs(it);
    }

    //post order
    //if you want dfs in post order then: 
    // cout<<node<<" "; 
}

int main(){
    for(int i=0; i<N; i++) vis[i]=0;
    int n, m; 
    cout<<"Enter the number of nodes: ";
    cin>>n;
    cout<<"Enter the number of edges: ";
    cin>>m;
    int x, y; 
    for(int i=0; i<m; i++){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cout<<"The DFS of the given adj list is: ";
    dfs(1);
    return 0;
}

/*
Enter the number of nodes: 7
Enter the number of edges: 7
1 2
1 3
2 4
2 5
2 6
2 7
7 3
The DFS of the given adj list is: 1 2 4 5 6 7 3
*/