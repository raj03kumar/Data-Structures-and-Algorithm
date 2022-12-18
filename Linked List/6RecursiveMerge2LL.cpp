/*
write a function to merge two sorted linked list.
2. Recursive way.
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

//merge two sorted linked list using recursion
struct node* mergeRecursive(struct node* head1, struct node* head2){
    //base case:
    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }

    struct node* result;

    if(head1->data<head2->data){
        result=head1;
        result->next=mergeRecursive(head1->next, head2);
    }
    else{
        result=head2;
        result->next=mergeRecursive(head1, head2->next);
    }

    return result;
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
    cout<<endl;

    traversal(mergeRecursive(head1, head2));

    return 0;
}