#include<bits/stdc++.h>
using namespace std;

int p=31; 
const int N = 1e5+7, m = 1e9+7;

vector<long long> power(N);

int main(){
    string s = "na";
    string t = "apnanacollegena";
    int S=s.size(), T=t.size();

    power[0]=1;
    for(int i=1;i<N; i++){
        power[i]=(power[i-1]*p)%m;
    }

    vector<long long> h(T+1, 0);
    for(int i=0; i<T; i++){
        h[i+1]=(h[i]+(t[i]-'a'+1)*power[i])%m;
    }

    long long h_s = 0;
    for(int i=0; i<S; i++){
        h_s=(h_s+(s[i]-'a'+1)*power[i])%m;
    }
    for(int i=0; i+S-1<T; i++){
        long long cur_h = (h[i+S]-h[i]+m)%m;
        if(cur_h == (h_s*power[i])%m){
            cout<<"Found at index "<<i<<"\n";
        }
    }
    return 0;
}