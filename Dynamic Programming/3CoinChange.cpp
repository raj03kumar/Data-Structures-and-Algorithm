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

const int N = 1e3+2, MOD = 1e9+7;

int dp[N][N];

int CoinChange(vi &a, int n, int x){
    if(x==0) return 1;
    if(x<0) return 0;
    if(n<=0) return 0;

    if(dp[n][x]!=-1){
        return dp[n][x];
    }

    dp[n][x]=CoinChange(a, n, x-a[n-1])+CoinChange(a, n-1, x);

    return dp[n][x];
}

int main(){
    rep(i, 0, N){
        rep(j, 0, N){
            dp[i][j]=-1;
        }
    }
    int n; cin>>n;
    vi a(n);
    rep(i,0,n){
        cin>>a[i];
    }
    int x; cin>>x;
    cout<<CoinChange(a, n, x);
    return 0;
}

/*
INPUT:
3
1 2 3
6
OUTPUT: 7
*/