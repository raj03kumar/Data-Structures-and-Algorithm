#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+2;
int a[N], tree[4*N];

void build(int node, int start, int end){
    if(start == end){
        tree[node] = a[start];
        return;
    }

    int mid = (start+end)/2;
    build(2*node, start, mid);
    build(2*node+1, mid+1, end);

    tree[node] = tree[2*node] + tree[2*node+1]; //we generally change this line according to our need
}

int main(){
    int n; cin>>n;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    build(1, 0, n-1);

    for(int i=1; i<16; i++){
        cout<<tree[i]<<endl;
    }
    return 0;
}

/*
INPUT:
8
5 3 2 4 1 8 6 10

OUTPUT:
39 --> root
14 --> left child
25 --> right child and so on
8 --> left child of 14
6 --> right child of 14 
9 --> left child of 25
16 --> right child of 25
5 --> left child of 8
3 --> right child of 8
2 --> left child of 6
4 --> right child of 6
1 --> left child of 9
8 --> right child of 9
6 --> left child of 16
10 --> right child of 16
*/