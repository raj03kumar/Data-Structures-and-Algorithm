#include<bits/stdc++.h>
using namespace std;

int main(){
    int ladders, snakes;
    cin>>ladders;
    map<int, int>lad, snak;
    for(int i=0; i<ladders; i++){
        int u, v; cin>>u>>v;
        lad[u]=v;
    }
    cin>>snakes;
    for(int i=0; i<snakes; i++){
        int u, v; cin>>u>>v;
        snak[u]=v;
    }
    int moves=0;
    queue<int>q;
    q.push(1);
    bool found=false;
    vector<int> vis(101, 0);
    vis[1]=true;
    while(!q.empty() and !found){
        int sz=q.size();
        while(sz--){
            int t=q.front();
            q.pop();
            for(int die=1; die<=6; die++){
                if(t+die==100){
                    found=true;
                }
                if(t+die<=100 and lad[t+die] and !vis[lad[t+die]]){
                    vis[lad[t+die]]=true;
                    if(lad[t+die]==100) found =true;
                    q.push(lad[t+die]);
                }
                else if(t+die<=100 and snak[t+die] and !vis[snak[t+die]]){
                    vis[snak[t+die]]=true;
                    if(snak[t+die]==100) found =true;
                    q.push(snak[t+die]);
                }
                // if it is an empty square
                else if(t+die<=100 and !vis[t+die] and !snak[t+die] and !lad[t+die]){
                    vis[t+die]=true;
                    q.push(t+die);
                }
            }
        }
        moves++;
    }

    if(found) cout<<moves;
    else cout<<-1;
    return 0;
}

/*
INPUT:
2
3 90
56 76
3
99 10
30 20
20 5
OUTPUT:
3
*/