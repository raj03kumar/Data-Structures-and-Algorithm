#include<bits/stdc++.h>
using namespace std;

const int N=1e5+6;
vector<int>parent(N);
vector<int>sz(N);
void make_set(int v){
    parent[v]=v;
    sz[v]=1;
}

int find_set(int v){
    if(v==parent[v]){
        return v;
    }
    return parent[v]=find_set(parent[v]);
}

void union_sets(int a, int b){
    a=find_set(a);
    b=find_set(b);
    if(a!=b){
        if(sz[a]<sz[b]) swap(a,b);
        parent[b]=a;
        sz[a]+=sz[b];
    }
}

int main(){
    for(int i=0; i<N; i++){
        make_set(i);
    }
    int n,m; cin>>n>>m;
    vector<vector<int>> edges;
    for(int i=0; i<m; i++){
        int u, v, w; cin>>u>>v>>w;
        edges.push_back({w,u,v});
    }
    sort(edges.begin(), edges.end());
    int cost=0;
    for(auto i: edges){
        int w=i[0];
        int u=i[1];
        int v=i[2];
        int x=find_set(u);
        int y=find_set(v);
        if(x==y) continue;
        else{
            cout<<u<<" "<<v<<endl;
            cost+=w;
            union_sets(u,v);
        }
    }
    cout<<"Cost: "<<cost;
    return 0;
}

/*
INPUT:
8 9
1 2 5
2 3 6
4 3 2
1 4 9
3 5 5
5 6 10
6 7 7
7 8 1
8 5 1
OUTPUT:
7 8
8 5
4 3
1 2
3 5
2 3
6 7
Cost: 27
*/