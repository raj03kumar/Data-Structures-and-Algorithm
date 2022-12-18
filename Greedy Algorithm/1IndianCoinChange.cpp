#include<bits/stdc++.h>
using namespace std;



int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    int x;
    cin>>x;

    sort(a.begin(), a.end(), greater<int>());
    int ans=0;

    for(int i=0; i<n; i++){
        ans+=x/a[i];
        x-=x/a[i]*a[i];
    }
    cout<<ans<<"\n";
    /*
    INPUT:
    10
    1 2 5 10 20 50 100 200 500 2000
    350
    OUTPUT:
    3
    */
    return 0;
}