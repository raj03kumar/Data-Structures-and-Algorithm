/*
program to place even places element of linked list after odd places in linked list.
*/

#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node *next;
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

//function to place even places elements of linked list after the odd places.
void evenAfterOdd(struct node* head){
    struct node* odd=head;
    struct node* even=head->next;
    struct node* evenStart=even;
    while(odd->next!=NULL and even->next!=NULL){
        odd->next=even->next;
        odd=odd->next;

        even->next=odd->next;
        even=even->next;
    }
    if(odd->next!=NULL){
        even->next=NULL;    //because even->next points to odd and it is not null in this case so we have to make it null to terminate the linked list.
    }
    odd->next=evenStart;
}

int main(){
    struct node *head = (struct node* )malloc(sizeof(struct node));
    head->next=NULL;
    head->data=1;
    
    int arr[]={2,3,4,5,6};
    
    for(int i=0; i<sizeof(arr)/sizeof(arr[0]); i++){
        insertAtEnd(head, arr[i]);
    }
    
    traversal(head);
    cout<<endl;
    
    evenAfterOdd(head);
    traversal(head);

    return 0;
}