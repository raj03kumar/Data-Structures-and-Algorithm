#include<bits/stdc++.h>
using namespace std;

int n; 
vector<int>bit;

int query(int idx){
    int ans = 0;
    while(idx>0){
        ans+=bit[idx];
        idx-=idx & (-idx);
    }
    return ans;
}

void update(int idx, int val){
    while(idx <= n){
        bit[idx]+=val;
        idx+=idx & (-idx);
    }
}

int main(){
    cin>>n;
    bit=vector<int>(n+1);
    vector<int>a(n+1);
    for(int i=1; i<=n; i++){
        cin>>a[i];
        update(i, a[i]);
    } 
    int q; cin>>q;
    while(q--){
        int c; cin>>c;
        if(c==1){
            //if the first index starts from 1 and not from 0. else we have to do l++ and r++
            int l,r; cin>>l>>r;
            int ans = query(r)-query(l-1);
            cout<<ans<<endl;
        }
        else if(c==2){
            int index, val; cin>>index>>val;
            update(index, -a[index]);
            a[index]=val;
            update(index, val);
        }
    }
    return 0;
}

/*
INPUT:
4
1 2 3 4
3 <-- 3 queries
1 1 4
10 <-- output
2 1 0
1 1 4
9 <-- output
*/