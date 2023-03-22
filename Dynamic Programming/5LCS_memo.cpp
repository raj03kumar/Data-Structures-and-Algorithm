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

int lcs(string &s1, string &s2, int n, int m){
    if(n==0 or m==0) return 0;
    if(dp[n][m]!=-1) return dp[n][m];
    if(s1[n-1]==s2[m-1]){
        dp[n][m] = 1+lcs(s1, s2, n-1, m-1);
    }
    else{
        dp[n][m] = max(lcs(s1, s2, n, m-1), lcs(s1, s2, n-1, m));
    }
    return dp[n][m];
}

int main(){
    rep(i, 0, N){
        rep(j, 0, N){
            dp[i][j]=-1;
        }
    }
    string s1, s2; cin>>s1>>s2;
    int n=s1.size(), m=s2.size();
    cout<<lcs(s1, s2, n, m);
    return 0;
}

/*
INPUT:
rishabh
shubhi
OUTPUT:
4
*/