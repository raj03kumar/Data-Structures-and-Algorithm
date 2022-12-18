#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node*next;

    node(int val){
        data=val;
        next=NULL;
    }
};

class myQueue{
    node* front;
    node* back;
    public:
    myQueue(){
        front=NULL;
        back=NULL;
    }
    void push(int a){
        node* n=new node(a);
        //for the beginning case when both front and back are null
        if(front==NULL){
            back=n;
            front=n;
            return;     //functions return from here in this case.
        }

        back->next=n;
        back=n;
    }
    void pop(){
        if(front==NULL){
            cout<<"Queue underflow"<<endl;
            return;
        }

        node* todelete=front;
        front=front->next;
        delete todelete;
    }

    //return the value of front pointer
    int peek(){
        if(front==NULL){
            cout<<"No element in queue"<<endl;
            return -1;
        }

        return front->data;
    }

    bool isEmpty(){
        if(front==NULL){
            return true;
        }

        return false;
    }
};

int main(){
    myQueue q;
    q.push(7);
    q.push(6);
    q.push(5);
    // q.push(4);
    // q.push(9);

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