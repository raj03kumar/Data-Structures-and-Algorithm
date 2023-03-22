#include<bits/stdc++.h>
using namespace std;

const int N=102, MOD=1e9+7;
int a[N]; int dp[N][N];

int main(){
    int n; cin>>n;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    for(int i=1; i<n; i++){
        dp[i][i]=0;
    }
    for(int l=2; l<n; l++){
        for(int i=1; i<n-l+1; i++){
            int j=i+l-1; 
            dp[i][j]=MOD;
            for(int k=i; k<j; k++){
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+a[i-1]*a[k]*a[j]); 
            }
        }
    }
    cout<<dp[1][n-1];
    return 0;
}