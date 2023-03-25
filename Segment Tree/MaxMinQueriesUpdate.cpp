#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e5+2;

int tree[4*N], a[N];

void build(int node, int start, int end){
    if(start == end){
        tree[node] = a[start];
        return;
    }

    int mid = (start+end)/2;
    build(2*node, start, mid);
    build(2*node+1, mid+1, end);

    tree[node] = max(tree[2*node], tree[2*node+1]); //we generally change this line according to our need
}

int query(int node, int start, int end, int l, int r){
    if(start > r or end <l) return INT_MIN;
    if(l<=start and end<=r) return tree[node];
    int mid = (start+end)/2;
    int q1 = query(2*node, start, mid, l, r);
    int q2 = query(2*node+1, mid+1, end, l, r);

    return max(q1, q2);
}

void update(int node, int start, int end, int idx, int val){
    if(start == end){
        a[start]=val;
        tree[node]=val;
        return;
    }
    int mid = (start+end)/2;
    if(idx<=mid){
        update(2*node, start, mid, idx, val);
    }
    else{
        update(2*node+1, mid+1, end, idx, val);
    }

    tree[node] = max(tree[2*node], tree[2*node+1]);
}

signed main(){
    int n; cin>>n;
    for(int i=0; i<n; i++) cin>>a[i];

    build(1, 0, n-1);

    while(1){
        int type; cin>>type;
        if(type==-1) break;

        if(type==1){
            int l, r;
            cin>>l>>r;
            int ans = query(1, 0, n-1, l, r);
            cout<<ans<<endl;
        }
        else if(type==2){
            int idx, val;
            cin>>idx>>val;
            update(1, 0, n-1, idx, val);
            cout<<query(1, 0, n-1, 0, n-1)<<endl;
        }
    }
    return 0;
}

/*
INPUT:
9
6 8 -1 2 17 1 3 2 4
1
2 6
17 <-- output
2
7 18
18 <-- output
-1 <-- input to break the loop
*/