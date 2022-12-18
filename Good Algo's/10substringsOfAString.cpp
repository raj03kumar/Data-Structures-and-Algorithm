#include<bits/stdc++.h>
using namespace std;
//generate all the substrings of a string using recursion.
// 2^n substrings.

//ALGORITHM: we start with an empty string. so on the next step we are adding a character to our ans and other time we are not adding any character to our string. 
/*
                         ""
                        /  \
(if we add char[0])    A    ""(if we dont add anything)
                      / \   /  \
                    AB  A   B   ""
                   / \ / \  / \  / \
                ABC AB AC A BC B C  ""  --> THIS IS OUR ANS.
*/

void subseq(string s, string ans){
    if (s.size()==0){
        cout<<ans<<endl;
        return;
    }
    char ch=s[0];
    subseq(s.substr(1), ans);
    subseq(s.substr(1), ans+ch);
}
int main(){
    subseq("RajKumar", "");
    return 0;
}