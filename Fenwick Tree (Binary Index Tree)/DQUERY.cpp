#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 2e5+2, MOD = 1e9+7;

struct Q{
    int l, r, idx;
};
int rootN;

Q q[N];

bool compare(Q q1, Q q2){
    if(q1.l/rootN == q2.l/rootN){
        return q1.r > q2.r;
    }
    return q1.l/rootN < q2.l/rootN;
}

signed main(){
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin>>a[i];
    rootN = sqrtl(n);
    int queries; cin>>queries;

    for(int i=0; i<queries; i++){
        int l, r; cin>>l>>r;
        q[i].l = l;
        q[i].r = r;
        q[i].idx = i;
    }

    sort(q, q+queries, compare);

    vector<int>ans(queries);
    int curr_l = 0, curr_r = -1, l, r;
    int curr_ans = 0;
    vector<int> freq(10*N, 0);
    for(int i=0; i<queries; i++){
        l = q[i].l; r = q[i].r;
        l--; r--;

        while(curr_r < r){
            curr_r++;
            freq[a[curr_r]]++;
            if(freq[a[curr_r]]==1) curr_ans++;
        }

        while(curr_l > l){
            curr_l--;
            freq[a[curr_l]]++;
            if(freq[a[curr_l]]==1) curr_ans++;
        }

        while(curr_l < l){
            freq[a[curr_l]]--;
            if(freq[a[curr_l]]==0) curr_ans--;
            curr_l++;
        }

        while(curr_r > r){
            freq[a[curr_r]]--;
            if(freq[a[curr_r]]==0) curr_ans--;
            curr_r--;
        }
        
        ans[q[i].idx] = curr_ans;
    }

    for(auto &i: ans) cout<<i<<endl;
    return 0;
}

/*
INPUT:
5
1 1 2 1 3
3
1 5
2 4
3 5
OUTPUT:
3
2
3
*/