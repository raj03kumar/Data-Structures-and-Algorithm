// Q2. Minimum number of squares whose sum equals to given number 'n'
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
int dp[N];

int MinSquare(int n){
    if(n<4) return n;
    if(dp[n]!=MOD){
        return dp[n];
    }
    for(int i=1; i*i<=n; i++){
        dp[n]=min(dp[n],1+MinSquare(n-i*i));
    }
    return dp[n];
}
int main(){
    rep(i, 0, N) dp[i]=MOD;
    int n; cin>>n;
    cout<<MinSquare(n);
    return 0;
}

/*
INPUT: 5, 1000
OUTPUT: 2, 2
*/