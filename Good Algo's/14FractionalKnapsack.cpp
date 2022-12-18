#include<bits/stdc++.h>
using namespace std;
/*
n is the number of items
m is the maximum weight of the bag
v is the values array
w is the weight array
p is the v/w ratio
*/
void knapsack(int n, int m, int v[], int w[]){
    float p[n];
    float amount=0;
    for(int i=0; i<n; i++){
        p[i]=(float)v[i]/w[i];
    }
    
    vector<pair<float, float>> v_new;
    vector<pair<float, float>> w_new;
    
    for(int i=0; i<n; i++){
        v_new.emplace_back(p[i], v[i]);
        w_new.emplace_back(p[i], w[i]);
    }
    
    sort(v_new.rbegin(), v_new.rend());
    sort(w_new.rbegin(), w_new.rend());
    
    for(int i=0; i<n; i++){
        if(m>0 and w_new[i].second<=m){
            amount+=v_new[i].second;
        }
        else if(m>0){
            amount+=v_new[i].second*(float)(m/w_new[i].second);
            // amount+=v_new[i].first*m;  --> this can also be used because we have stored the value of v/w in v_new.first
        }
        m-=w_new[i].second;
    }
    cout<<"The maximum amount that can be generated is : "<<amount;
}

int main(){
    int n;
    cout<<"Enter the number of items: ";
    cin>>n;
    int m;
    cout<<"Enter the maximum weight of the knapsack: ";
    cin>>m;
    int v[n];
    cout<<"Enter the value of items in the bag: ";
    for(int i=0; i<n; i++){
        cin>>v[i];
    }
    int w[n];
    cout<<"Enter the consecutive weight of items in the bag: ";
    for(int i=0; i<n; i++){
        cin>>w[i];
    }
    knapsack(n, m , v, w);
    return 0;
}