#include<bits/stdc++.h>
using namespace std;

priority_queue<int, vector<int> , greater<int>> pqmin;
priority_queue<int, vector<int>> pqmax;

void insert(int x){
    if(pqmax.size()==pqmin.size()){
        if(pqmax.size()==0){
            pqmax.push(x);
            return;
        }

        if(x<pqmax.top()){
            pqmax.push(x);
        }
        else{
            pqmin.push(x);
        }
    }
    else{
        //if the size are not equal
        //two cases possible. Case 1: size of maxheap > size of minheap
        //Case 2: size of minHeap > size of maxHeap

        if(pqmax.size()>pqmin.size()){
            if(x>=pqmax.top()){
                pqmin.push(x);
            }
            else{
                int temp=pqmax.top();
                pqmax.pop();
                pqmin.push(temp);
                pqmax.push(x);
            }
        }
        else{
            if(x<=pqmin.top()){
                pqmax.push(x);
            }
            else{
                int temp=pqmin.top();
                pqmin.pop();
                pqmax.push(temp);
                pqmin.push(x);
            }
        }
    }
}

double findMedian(){
    if(pqmax.size()==pqmin.size()){
        return (pqmin.top()+pqmax.top())/2.0;
    }
    else if(pqmax.size()>pqmin.size()){
        return pqmax.top();
    }
    else{
        return pqmin.top();
    }
}

int main(){
    int n;
    while(true){
        cout<<"Enter the number: ";
        cin>>n;
        insert(n);
        cout<<"Running Median is: "<<findMedian()<<endl;
        cout<<"------------------------Press ctrl+c to exit------------------------\n";
    }
    return 0;
}