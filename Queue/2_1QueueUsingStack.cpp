#include<bits/stdc++.h>
using namespace std;

class myQueue{
    stack <int> s1;
    public:
    void push(int x){
        s1.push(x);
    }
    int pop(){
        if(s1.empty()){
            cout<<"The queue is empty\n";
            return -1;
        }
        int a=s1.top();
        s1.pop();
        if(s1.empty()){
            return a;
        }
        int item=pop();     //recursively pop out
        s1.push(a);
        return item;
    }
    bool isEmpty(){
        if(s1.empty()){
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