#include<bits/stdc++.h>
using namespace std;

void reverseSentence(string s){
    stack<string> st;
    for(int i=0; i<s.length(); i++){
        string word="";
        //till we dont get a space we have to add the char to word sting.
        while(s[i]!=' ' and i<s.length()){          //note use ' ' instead of " ";
            word+=s[i];
            i++;
        }
        st.push(word);
    }
    //now we have to print the elements.
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}

int main(){
    string s;
    getline(cin,s);
    reverseSentence(s);
    return 0;
}