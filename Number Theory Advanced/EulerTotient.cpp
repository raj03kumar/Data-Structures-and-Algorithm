#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+2, MOD=1e9+7;

int totient[N];
signed main(){
    for(int i=0; i<N; i++){
        totient[i]=i;
    }
    for(int i=2; i<N; i++){
        if(totient[i]==i){
            for(int j=2*i; j<N; j+=i){
                totient[j]*=i-1;
                totient[j]/=i;
            }
            totient[i]=i-1;
        }
    }

    for(int i=2; i<11; i++){
        cout<<totient[i]<<" ";
    }
    return 0;
}