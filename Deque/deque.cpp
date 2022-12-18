#include<bits/stdc++.h>
using namespace std;

void display(deque<int> dq){
    for(auto i: dq){
        cout<<i<<" ";
    }
    cout<<endl;
}

int main(){
    deque<int> dq;
    dq.push_back(1);
    dq.push_back(2);
    dq.push_front(3);
    dq.push_front(4);
    display(dq);
    dq.pop_back();
    display(dq);
    dq.pop_front();
    display(dq);
    return 0;
}