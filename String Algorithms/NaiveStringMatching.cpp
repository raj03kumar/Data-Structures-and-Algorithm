#include<bits/stdc++.h>
using namespace std;

int main(){
    string s = "an";
    string t = "netherlands and holland are same place";
    int S = s.size(), T = t.size();
    for(int i=0; i<T-S+1; i++){
        if(t.substr(i, S)==s) cout<<"Found at index "<<i<<endl;
    }
    return 0;
}