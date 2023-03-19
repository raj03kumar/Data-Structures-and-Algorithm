// Adjacency list representation

#include<bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i,a,b) for(int i=a; i<b; i++)
#define ff first
#define ss second
#define setBits(x) builtin_popcount(x)

const int N = 1e5+2, MOD = 1e9+7;

// Global adjacency list
vi adj[N];

int main(){
    int n, m; 
    cout<<"Enter the number of nodes: ";
    cin>>n;
    cout<<"Enter the number of edges: ";
    cin>>m;
    rep(i,0,m){
        int x, y; cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    cout<<"adjacency list of above graph is given by: "<<endl;
    rep(i, 1, n+1){
        cout<<i<<" -> ";
        for(auto x: adj[i]) cout<<x<<" ";
        cout<<endl;
    }
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
adjacency list of above graph is given by:
1 -> 2 3
2 -> 1 4 5 6 7
3 -> 1 7
4 -> 2
5 -> 2
6 -> 2
7 -> 2 3
*/