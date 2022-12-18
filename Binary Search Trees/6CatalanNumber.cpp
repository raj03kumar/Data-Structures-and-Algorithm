#include<bits/stdc++.h>
using namespace std;

int catalan(int n){
    //base case:
    if(n<=1){
        return 1;
    }

    int res=0;
    for(int i=0; i<n; i++){
        res+=catalan(i)*catalan(n-1-i);
    }
    return res;
}
//but this program has very high time complexity. So we use dynamic programming to solve for catalan numbers.
int main(){
    for(int i=0; i<10; i++){
        cout<<catalan(i)<<" ";
    }
    return 0;
}   