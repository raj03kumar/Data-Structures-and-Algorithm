/*
write a function to merge two sorted linked list.
1. iterative way
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
//this is iterative way of merging two linked list
struct node* merge(struct node*head1, struct node*head2){
    struct node*p1=head1;
    struct node*p2=head2;
    //note dummy node is a node and not a pointer to a node.
    struct node* dummyNode=(struct node*)malloc(sizeof(struct node));
    struct node*p3=dummyNode;

    while(p1!=NULL and p2!=NULL){
        if(p1->data<p2->data){
            p3->next=p1;
            p1=p1->next;
        }
        else{
            p3->next=p2;
            p2=p2->next;
        }
        p3=p3->next;
    }

    //now to add individually with p1 gets over.
    while(p1!=NULL){
        p3->next=p1;
        p1=p1->next;
        
        p3=p3->next;
    }
    while(p2!=NULL){
        p3->next=p2;
        p2=p2->next;
        
        p3=p3->next;
    }
    return dummyNode->next;
}

int main(){
    struct node *head1 = (struct node* )malloc(sizeof(struct node));
    struct node *head2 = (struct node* )malloc(sizeof(struct node));
    head1->next=NULL;
    head2->next=NULL;
    head1->data=0;
    head2->data=1;
    int arr1[]={2,3,6};
    int arr2[]={1,2,4,5,9,18};
    for(int i=0; i<sizeof(arr1)/sizeof(arr1[0]); i++){
        insertAtEnd(head1, arr1[i]);
    }
    for(int i=0; i<sizeof(arr2)/sizeof(arr2[0]); i++){
        insertAtEnd(head2, arr2[i]);
    }
    
    traversal(head1);
    cout<<endl;
    traversal(head2);
    //now we have to merge these two linked list and print them.
    cout<<endl;
    traversal(merge(head1, head2));//this is iterative approach.
    return 0;
}