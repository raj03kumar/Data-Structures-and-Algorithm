#include<bits/stdc++.h>
using namespace std;
const int N =1e5+2, MOD=1e9+7;
// ax+by=gcd(a,b)

struct triplet{
    int x, y, gcd;
};

triplet extendedEuclid(int a, int b){
    if(b==0){
        triplet ans;
        ans.x=1;
        ans.gcd=a;
        ans.y=0;
        return ans;
    }

    triplet smallAns=extendedEuclid(b, a%b);
    triplet ans;
    ans.gcd=smallAns.gcd;
    ans.x=smallAns.y;
    ans.y=smallAns.x-(a/b)*smallAns.y;
    return ans;
}

int multiplicativeModuloInverse(int a, int m){
    triplet temp=extendedEuclid(a,m);
    return temp.x;
}

int main(){
    int a, m; cin>>a>>m;

    int ans=multiplicativeModuloInverse(a,m);
    if(ans<0) cout<<m+ans;
    else cout<<ans;
    return 0;
}

/*
INPUT:
17 3
OUTPUT:
2
*/