/*
we write a function to find the length of the linked list.
we write our function kAppend.
*/

#include<iostream>
using namespace std;

struct node{
    int data;
    struct node* next;
};
void traversal(struct node *ptr){
    while(ptr!=NULL){
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
}
struct node * insertAtEnd(struct node *head, int data){
    struct node *ptr=(struct node*)malloc(sizeof(struct node));
    struct node *p=head;
    ptr->data=data;
    while(p->next!=NULL){
        p=p->next;
    }
    ptr->next=NULL;
    p->next=ptr;
    return head;
}

int length(struct node* head){
    //function to find the length of the linked list.
    int l=0;
    struct node*temp=head;
    while(temp!=NULL){
        l++;
        temp=temp->next;
    }
    return l;
}

struct node* kAppend(struct node* head, int k){
    struct node* newHead;
    struct node* newTail;
    struct node* tail=head;    

    int l =length(head);
    k=k%l; //if we are given k is greater than l.
    int count=1;
    while(tail->next!=NULL){
        if(count==l-k){
            newTail=tail;
        }
        if(count==l-k+1){
            newHead=tail;
        }
        tail=tail->next;
        count++;
    }

    //now we have to change our links
    newTail->next=NULL;
    tail->next=head;
    return newHead;

}

int main(){
    struct node *head = (struct node* )malloc(sizeof(struct node));
    cout<<"Enter the data of head node: ";
    cin>>head->data;
    head->next=NULL;
    insertAtEnd(head, 2);
    insertAtEnd(head, 3);
    insertAtEnd(head, 4);
    insertAtEnd(head, 5);
    insertAtEnd(head, 6);
    insertAtEnd(head, 7);
    insertAtEnd(head, 8);
    traversal(head);
    cout<<endl;
    head=kAppend(head, 3);
    traversal(head);
    
    return 0;
}