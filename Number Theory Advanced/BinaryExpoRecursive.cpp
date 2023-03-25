#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=1e5+2, MOD=1e9+7;

int power(int a, int n){
    if(n==0) return 1;
    int p=(power(a, n/2)%MOD);
    if(n&1){
        return (((p*p)%MOD)*a)%MOD;
    }
    else{
        return (p*p)%MOD;
    }
}

signed main(){
    int a, n; cin>>n;
    a%=MOD;
    cout<<power(a,n);
    return 0;
}