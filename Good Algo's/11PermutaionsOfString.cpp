#include<bits/stdc++.h>
using namespace std;
//print all the possible permutations of the string
//Time Complexity is n*n!. there are n! factorial and it requires n time to rpint all those factorial.
// --> you can see the diagram from g4g
void permutation(string s, string ans){
    if(s.length()==0){
        cout<<ans<<endl;
        return;
    }
    for(int i=0; i<s.length(); i++){
        char ch=s[i];
        string ros=s.substr(0,i)+s.substr(i+1);     //ros means rest of string
        permutation(ros, ans+ch);
    }
}
int main(){
    permutation("ABC","");
    return 0;
}