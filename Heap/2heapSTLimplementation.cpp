#include<bits/stdc++.h>
using namespace std;

int main(){
    priority_queue<int, vector<int>> pq;
    pq.push(2);
    pq.push(3);
    pq.push(1);

    cout<<pq.top()<<endl;//returns 3 because 3 is the top element in max heap.
    pq.pop();
    cout<<pq.top()<<endl;//returns 2 because 2 is the top element in max heap.


    priority_queue<int, vector<int>, greater<int>> min_pq;
    min_pq.push(9);
    min_pq.push(6);
    min_pq.push(5);

    cout<<min_pq.top()<<endl;//returns 5 because 5 is the top element in min heap.
    min_pq.pop();
    cout<<min_pq.top()<<endl;//returns 6 because 6 is the top element in min heap.


    return 0;
}   