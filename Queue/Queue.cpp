//implementation of Queue in cpp
#include<bits/stdc++.h>
using namespace std;
#define n 50

class myQueue{
    int front;
    int back;
    int *arr;

    public:
    myQueue(){
        arr=new int [n];
        front=-1;
        back=-1;
    }
    void push(int a){
        if(back==n-1){
            cout<<"myQueue is full\n";
            return ;
        }
        back++;
        arr[back]=a;

        //for the only first time we check:
        if(front==-1){
            front++;
        }
    }
    void pop(){
        //we check if the myQueue is empty or not and we check it by checking if 
        if(front==-1 or front>back){
            cout<<"myQueue is empty\n";
            return;
        }
        front++;
    }
    int peek(){
        if(front==-1 or front>back){
            cout<<"myQueue is empty\n";
            return -1;
        }
        return arr[front];
    }
    bool isEmpty(){
        if(front==-1 or front>back){
            // cout<<"myQueue is empty\n";
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

    cout<<q.peek()<<endl;
    q.pop();
    cout<<q.peek()<<endl;
    q.pop();
    cout<<q.peek()<<endl;
    q.pop();
    cout<<q.peek()<<endl;
    q.pop();

    cout<<q.isEmpty();
    return 0;
}