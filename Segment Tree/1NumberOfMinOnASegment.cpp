#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e5+2, MOD = 1e9+7;

pair<int,int> tree[4*N]; 
int a[N];

void build(int node, int start, int end){
    if(start == end){
        tree[node].first = a[start];
        tree[node].second = 1; //to store the freq
        return;
    }

    int mid = (start+end)/2;
    build(2*node, start, mid);
    build(2*node+1, mid+1, end);

    if(tree[2*node].first < tree[2*node+1].first){
        tree[node].first = tree[2*node].first;
        tree[node].second = tree[2*node].second;
    }
    else if(tree[2*node+1].first < tree[2*node].first){
        tree[node].first = tree[2*node+1].first;
        tree[node].second = tree[2*node+1].second;
    }
    else{
        // if they are equal then we can put any of them
        tree[node].first = tree[2*node].first;
        //but the count will get added
        tree[node].second = tree[2*node].second + tree[2*node+1].second;
    }
}

pair<int,int> query(int node, int start, int end, int l, int r){
    if(start > r or end <l) return {MOD, -1};
    if(l<=start and end<=r) return tree[node];
    int mid = (start+end)/2;
    pair<int, int> q1 = query(2*node, start, mid, l, r);
    pair<int, int> q2 = query(2*node+1, mid+1, end, l, r);

    pair<int, int> q; //just temp ans variable

    if(q1.first < q2.first){
        q = q1;
    }
    else if (q2.first < q1.first){
        q = q2;
    }
    else{
        q.first = q1.first;
        q.second = q1.second+q2.second;
    }
    return q;
}

void update(int node, int start, int end, int idx, int val){
    if(start == end){
        a[start]=val;
        tree[node].first=val;
        tree[node].second=1;
        return;
    }
    int mid = (start+end)/2;
    if(idx<=mid){
        update(2*node, start, mid, idx, val);
    }
    else{
        update(2*node+1, mid+1, end, idx, val);
    }
    //copied from build
    if(tree[2*node].first < tree[2*node+1].first){
        tree[node].first = tree[2*node].first;
        tree[node].second = tree[2*node].second;
    }
    else if(tree[2*node+1].first < tree[2*node].first){
        tree[node].first = tree[2*node+1].first;
        tree[node].second = tree[2*node+1].second;
    }
    else{
        // if they are equal then we can put any of them
        tree[node].first = tree[2*node].first;
        //but the count will get added
        tree[node].second = tree[2*node].second + tree[2*node+1].second;
    }
}

signed main(){
    int n, m; cin>>n>>m;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    build(1, 0, n-1); // without building nothing will happen. This is very important step.
    while(m--){
        int type; cin>>type;
        if(type==1){
            //update
            int idx, val;
            cin>>idx>>val;
            update(1, 0, n-1, idx, val);
        }
        else if(type==2){
            //query
            int l, r; cin>>l>>r;

            pair<int, int> ans = query(1, 0, n-1, l, r-1);
            cout<<ans.first<<" "<<ans.second<<endl;
        }
    }
    return 0;
}

/*
INPUT:
5 5
3 4 3 5 2
2 0 3
1 1 2
2 0 3
1 0 2
2 0 5
OUTPUT:
3 2
2 1
2 3
*/

/*
INPUT:
5 5
3 4 3 5 2
2 0 3
3 2 <-- output
1 1 2
2 0 3
2 1 <-- output
1 0 2
2 0 5
2 3 <-- output
*/