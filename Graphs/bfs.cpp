// BREADTH FIRST SEARCH
#include<bits/stdc++.h>
using namespace std;

const int N=1e5+2;
bool vis[N];
vector<int> adj[N];

int main(){
    for(int i=0; i<N; i++) vis[i]=0;
    int n, m; 
    cout<<"Enter the number of nodes: ";
    cin>>n;
    cout<<"Enter the number of edges: ";
    cin>>m;
    int x, y; 
    for(int i=0; i<m; i++){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    queue<int>q;
    q.push(1);
    vis[1]=true;
    cout<<"The BFS of the given adj list is: "<<endl;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        cout<<node<<endl;
        for(auto it: adj[node]){
            if(!vis[it]){
                vis[it]=1;
                q.push(it);
            }
        }
    }
    return 0;
}

/*
Enter the number of nodes: 7
Enter the number of edges: 7
1 2
1 3
2 4
2 5
2 6
2 7
7 3
The BFS of the given adj list is:
1
2
3
4
5
6
7
*/