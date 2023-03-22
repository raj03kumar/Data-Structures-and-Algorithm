// LIS Using tabulation
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
    int n; cin>>n;
    vi a(n);
    rep(i, 0, n){
        cin>>a[i];
    }
    vi dp(n, 1);
    int ans=0;
    rep(i, 1, n){
        rep(j, 0, i){
            if(a[i]>a[j]){
                dp[i]=max(dp[i], 1+dp[j]);
            }
        }
        ans=max(ans, dp[i]); 
    }
    cout<<ans;
    return 0;
}