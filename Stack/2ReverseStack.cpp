#include<bits/stdc++.h>
using namespace std;

void insertAtBottom(stack <int> &st, int top){      
    //we are sending reference because this is a void function all the changes will be made in the stack only.
    //base condition:
    if(st.empty()){
        st.push(top);
        return;
    }
    int ele=st.top();
    st.pop();
    insertAtBottom(st, top);
    st.push(ele);
}

void reverseStack(stack <int> &st){
    //base condition:
    if(st.empty()){
        return;
    }

    int top=st.top();
    st.pop();
    reverseStack(st);
    insertAtBottom(st, top);
}

void display(stack <int> s){
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<"\n";
}

int main(){
    stack <int> s;
    s.push(5);
    s.push(50);
    s.push(25);
    s.push(53);
    s.push(54);
    display(s);
    reverseStack(s);
    display(s);
    
    return 0;
}