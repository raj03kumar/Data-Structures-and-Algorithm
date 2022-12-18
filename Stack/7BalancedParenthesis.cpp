#include<bits/stdc++.h>
using namespace std;

bool isValid(string s){
    stack <char>st;
    bool ans=true;
    for(int i=0; i<s.size();i++){
        //if we get any bracket then we push it to stack
        if(s[i]=='(' or s[i]=='{' or s[i]=='[') st.push(s[i]);
        
        else if(s[i]==')'){
            if(!st.empty() and st.top()=='(') st.pop();
            else {
                ans=false;
                break;
            }
        }
        else if(s[i]=='}'){
            if(!st.empty() and st.top()=='{') st.pop();
            else {
                ans=false;
                break;
            }
        }
        else if(s[i]==']'){
            if(!st.empty() and st.top()=='[') st.pop();
            else {
                ans=false;
                break;
            }
        }
    }
    //we check if still there is any element left inside the stack or not.
    if(!st.empty()) ans=false;
    return ans;
}

int main(){
    string s;
    getline(cin, s);
    //(a+b){a+(a-b)}
    // Valid string
    // ({})[(){}]
    // Valid string
    if(isValid(s)){
        cout<<"Valid string\n";
    }
    else{
        cout<<"InValid String\n";
    }
    return 0;
}