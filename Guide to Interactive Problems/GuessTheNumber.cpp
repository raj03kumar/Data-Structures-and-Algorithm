#include<bits/stdc++.h>
using namespace std;

int main(){
    int lo = 1, hi=1000000;
    int ans = -1;
    while(lo<=hi){
        int mid = (lo+hi)/2;
        cout<<mid<<endl;
        cout<<flush;
        string s; cin>>s;
        if(s=="<"){
            hi=mid - 1;
        }
        else{
            // >=
            ans=max(ans, mid);
            lo = mid+1;
        }
    }
    cout<<"! "<<ans<<endl;
    cout<<flush;
    return 0;
}

//interact yourself also

/*
500000
< 
250000
<
125000
<
62500
<
31250
<
15625
<
7812
<
3906
<
1953
<
976
<
488
<
244
<
122
<
61
>
91
>
106
<
98
<
94
<
92
<
! 91
*/