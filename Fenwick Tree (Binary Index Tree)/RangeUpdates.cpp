#include<bits/stdc++.h>
using namespace std;

int query(int i, int bit[], int n){
    int ans = 0;
    while(i>0){
        ans += bit[i];
        i -= i & (-i);
    }
    return ans;
}

void update(int i, int inc, int bit[], int n){
    while(i<= n){
        bit[i]+=inc;
        i+=i & (-i);
    }
}

int main(){
    int n; cin>>n;
    int bit[n+10] = {0};
    int u; cin>>u;
    while(u--){
        int l, r, inc;
        cin>>l>>r>>inc;
        l++; r++;
        update(l, inc, bit, n); //A[L..]+inc
        update(r+1, -inc, bit, n); //A[R+1...] - inc
        //A[L..R] + inc
    }
    int q; cin>>q;
    while(q--){
        int w; cin>>w;
        w++; // for 1 based indexing
        cout<<query(w, bit, n)<<endl;
    }
    return 0;
}

/*
INPUT:
5 3
0 1 7
2 4 6
1 3 2
3 
0 
7 <-- output
3
8 <-- output
4
6 <-- output
*/