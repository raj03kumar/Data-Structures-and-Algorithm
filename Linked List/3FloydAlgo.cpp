#include<iostream>
using namespace std;

// --> note: we also have to make a function to make a cycle in a linked list which is given in apni kaksha

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

void makeCycle(struct node* head, int pos){
    struct node*temp=head;
    struct node* startNode;     //it is the startNode of the cycle...

    int count=1;
    while(temp->next!=NULL){
        if(count==pos){
            startNode=temp;
        }
        temp=temp->next;
        count++;
    }
    //remember that now temp->next=NULL because we have exited the loop. so this is a basic straight linked list. so to make a cycle we have to point temp->next to starting of the cycle.
    temp->next=startNode;
}



// code:

bool detectCycle(struct node* head){
    struct node* slow=head;
    struct node* fast=head;

    while(fast!=NULL and fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;

        if(fast==slow){
            return true;
        }
    }
    return false;
}

void removeCycle(struct node* head){
    //note here we assume that we have already detected the cycle and we are going to remove that cycle.
    struct node*slow=head;
    struct node*fast=head;

    do{             
        //we use do while because we want this to run at least one time because initially slow==fast. so the loop runs once and after that we start checking.
        
        fast=fast->next->next;
        slow=slow->next;
    }while(slow!=fast);

    // now we do fast=head and move the pointers with only one step.
    
    fast=head;
    while(fast->next!=slow->next){
        fast=fast->next;
        slow=slow->next;
    }

    slow->next=NULL; //Hence the cycle is removed.

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
    
    makeCycle(head, 3);
    // traversal(head); because this is infinite now
    cout<<endl;
    cout<<"Detect cycle: "<<detectCycle(head)<<"\n";
    removeCycle(head);
    cout<<"Detect cycle: "<<detectCycle(head)<<"\n";


    return 0;
}

