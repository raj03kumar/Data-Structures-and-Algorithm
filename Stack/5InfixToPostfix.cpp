/*
we have to convert a given infix string to postfix string.
PSUEDOCODE:
we traverse our string from left to right 
if(operand) then print;
if '(' then push to stack;
if ')' then pop from stack and print until we find '(';
if operator: then pop and print from stack until an operator with less precedence is found. if found then we push this operator to stack.

*/
#include<bits/stdc++.h>
using namespace std;
//this function returns the precedencce of the operators.
int prec(char c){
    if(c=='^')return 3;
    else if(c=='*'|| c=='/')return 2;
    else if(c=='+'||c=='-')return 1;
    else{
        return -1;      //-1 when we find parenthesis.
    }
}
string infixToPostfix(string s){
    stack<char> st;
    string ans;
    for(int i=0; i<s.length(); i++){
        if((s[i]>='a' and s[i]<='z')or(s[i]>='A' and s[i]<='Z')){
            ans+=s[i];
        }
        else if(s[i]=='('){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            //we pop until we get the opening bracket.
            while(!st.empty() and st.top()!='('){
                ans+=st.top();
                st.pop();
            }
            //the above loops stops if it finds opening parenthesis. so we have to pop that unnecessary bracket now.
            if(!st.empty()){
                st.pop();
            }
        }
        //now we see the case when operators come.
        else{
            while(!st.empty() and prec(st.top())>prec(s[i])){
                ans+=st.top();
                st.pop();
            }
            //after all these we push our current element to stack
            st.push(s[i]);
        }
    }
    //now we have to check that if our stack is empty or not. if it is not empty then we have to add all those element at last to our string
    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
    return ans;
}

int main(){
    cout<<infixToPostfix("(a-b/c)*(a/k-l)");
    // abc/-ak/l-* is the ans.
    return 0;
}