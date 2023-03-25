#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<string> strings = {"aa", "ab", "aa", "b", "cc", "ab"};
    unordered_set<string> s(strings.begin(), strings.end());
    cout<<s.size();
    return 0;
}