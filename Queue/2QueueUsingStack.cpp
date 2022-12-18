#include<bits/stdc++.h>
using namespace std;

class myQueue{
    stack <int> s1;
    stack <int> s2;
    public:
    void push(int x){
        s1.push(x);
    }
    int pop(){
        if(s1.empty() and s2.empty()){
            cout<<"The queue is empty\n";
            return -1;
        }
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        int topval=s2.top();
        s2.pop();
        return topval;
    }
    bool isEmpty(){
        if(s1.empty() and s2.empty()){
            return true;
        }
        return false;
    }
};

int main(){
    myQueue q;
    q.push(9);
    q.push(5);
    q.push(3);
    q.push(8);

    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    // cout<<q.pop()<<endl;
    // cout<<q.pop()<<endl;
    cout<<q.isEmpty();
    return 0;
}   