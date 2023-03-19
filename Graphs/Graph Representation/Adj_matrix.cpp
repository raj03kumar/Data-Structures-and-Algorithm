// Adjacency matrix representaion

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

int main(){
    int n, m; 
    cout<<"Enter the number of nodes: ";
    cin>>n;
    cout<<"Enter the number of edges: ";
    cin>>m;
    vvi adjm(n+1, vi(n+1, 0));

    rep(i, 0, m){
        int x, y; cin>>x>>y;

        adjm[x][y]=1;
        adjm[y][x]=1;
    }
    cout<<"adjacency matrix of above graph is given by: "<<endl;
    rep(i, 1, n+1){
        rep(j, 1, n+1){
            cout<<adjm[i][j]<<" ";
        }
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
adjacency matrix of above graph is given by: 
0 1 1 0 0 0 0 
1 0 0 1 1 1 1 
1 0 0 0 0 0 1 
0 1 0 0 0 0 0
0 1 0 0 0 0 0
0 1 0 0 0 0 0
0 1 1 0 0 0 0
*/