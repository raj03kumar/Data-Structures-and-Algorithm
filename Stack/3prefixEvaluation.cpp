#include<bits/stdc++.h>
using namespace std;

int prefixEval(string s){
    stack <int> st;
    //we start traversing sting from back.
    for(int i=s.size()-1; i>=0; i--){
        //we now check if it a operand
        if(s[i]>='0' and s[i]<='9' ){
            st.push(s[i]-'0'); //NOTE: s[i]-'0' is the value of integer and it is not a string.
        }
        else{
            int a=st.top();
            st.pop();
            int b=st.top();
            st.pop();

            switch(s[i]){
                case '+':
                    st.push(a+b);
                    break;
                case '-':
                    st.push(a-b);
                    break;
                case '*':
                    st.push(a*b);
                    break;
                case '/':
                    st.push(a/b);
                    break;
                default:
                    break;
            }
        }
    }
    return st.top();
}

int main(){
    cout<<prefixEval("-+7*45+20");//ans is 25
    return 0;
}