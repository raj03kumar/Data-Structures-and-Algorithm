#include<bits/stdc++.h>
using namespace std;



int main(){
    string s;
    cout<<"Enter the String: ";
    cin>>s;
    stack<char> st;
    bool ans=false;
    for(int i=0; i<s.size(); i++){
        //if we get any operator or an '(' then we push it so stack
        if(s[i]=='+' or s[i]=='-' or s[i]=='*' or s[i]=='/' or s[i]=='('){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            //check if the stack top element is '(' or not if yes then return true
            if(st.top()=='('){
                ans= true;
            }
            //else we pop out the operators
            while(s[i]=='+' or s[i]=='-' or s[i]=='*' or s[i]=='/'){
                st.pop();
            }
            st.pop();
        }
    }
    cout<<ans;
    return 0;
}