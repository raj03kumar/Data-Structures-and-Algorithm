#include<bits/stdc++.h>
using namespace std;

int postfixEval(string s){
    stack <int> st;
    //we start traversing sting from back.
    for(int i=0; i<s.size(); i++){
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
    cout<<postfixEval("75+");//ans is 12
    cout<<endl;
    cout<<postfixEval("46+2/5*7+");     //ans is 7. also ans depends on what we are dividing. it we are pushing a/b then ans is 7 bt if we are pushing b/a then the ans is different.
    return 0;
}