/*
here we have to traverse from right to left.
so we just reverse the elements and also revert back the reverted parenthesis.
NOTE: It is same as postfix just the brackets are different.
*/

#include<bits/stdc++.h>
using namespace std;

int prec(char c){
    if(c=='^')return 3;
    else if(c=='*'|| c=='/')return 2;
    else if(c=='+'||c=='-')return 1;
    else{
        return -1;      //-1 when we find parenthesis.
    }
}
string infixToPrefix(string s){
    reverse(s.begin(), s.end());
    stack<char>st;
    string ans;
    for(int i=0; i<s.length(); i++){
        if((s[i]>='a' and s[i]<='z')or(s[i]>='A' and s[i]<='Z')){
            ans+=s[i];
        }
        else if(s[i]==')'){
            st.push(s[i]);
        }
        else if(s[i]=='('){
            //we pop until we get the opening bracket.
            while(!st.empty() and st.top()!=')'){
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

    reverse(ans.begin(), ans.end());
    return ans;
}

int main(){
    cout<<infixToPrefix("(a-b/c)*(a/k-l)");
    // *-a/bc-/akl is the ans
    return 0;
}