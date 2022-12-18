/*
we write a function to find the intersection point of two linkedlist.
we also have to write a lenght function and a intersect function which will intersect two linked list.
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

//function to find the length of the linked list.
int length(struct node* head){
    int l=0;
    struct node*temp=head;
    while(temp!=NULL){
        l++;
        temp=temp->next;
    }
    return l;
}
//this function adds the last node of linkedlist2 to the given position of linkedlist 1.
void intersect(struct node* head1, struct node* head2, int pos){
    struct node* temp1=head1;
    pos--;
    while(pos--){
        temp1=temp1->next;
    }
    struct node* temp2=head2;
    while(temp2->next!=NULL){
        temp2=temp2->next;
    }

    temp2->next=temp1;
}

//function to find intersection point of two linked list.
int intersection(struct node* head1, struct node* head2){
    int l1=length(head1);
    int l2=length(head2);

    int d=0;
    struct node* ptr1;
    struct node* ptr2;
    //now find which linked list is bigger so that ptr1 points to the bigger linked list and ptr2 points to the shorter linked list.
    if(l1>l2){
        d=l1-l2;
        ptr1=head1;
        ptr2=head2;
    }
    else{
        d=l2-l1;
        ptr1=head2;
        ptr2=head1;
    }
    //now we have to increase the pointer of the longer linked list.
    while(d){
        ptr1=ptr1->next;
        if(ptr1==NULL) {
            return -1;
        }
        d--;
    }
    //now we simply increase both pointers with one step and checck if they are equal or not. 
    while(ptr1!=NULL and ptr2!=NULL){
        if(ptr1==ptr2){
            return ptr1->data;
        } 
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    return -1;
}


int main(){
    struct node *head1 = (struct node* )malloc(sizeof(struct node));
    struct node *head2 = (struct node* )malloc(sizeof(struct node));
    cout<<"Enter the data of head1 node: ";
    cin>>head1->data;
    head1->next=NULL;
    cout<<"Enter the data of head2 node: ";
    cin>>head2->data;
    head2->next=NULL;
    insertAtEnd(head1, 2);
    insertAtEnd(head1, 4);
    insertAtEnd(head1, 5);
    insertAtEnd(head1, 6);
    insertAtEnd(head1, 7);
    insertAtEnd(head1, 8);

    insertAtEnd(head2, 10);

    intersect(head1, head2, 5);
    traversal(head1);
    cout<<endl;
    traversal(head2);
    cout<<"\nThe intersection point is: "<<intersection(head1, head2);
        
    return 0;
}