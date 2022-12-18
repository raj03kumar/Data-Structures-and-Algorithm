#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* left, *right;
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

void calcPointers(Node* root, Node**first, Node**mid, Node**last, Node**prev){
    // this is like inorder
    if(root==NULL){
        return;
    }
    calcPointers(root->left, first, mid, last, prev);
    //now we check the cases.
    if(*prev and root->data<(*prev)->data){
        // we have to check if our property is violating first time or second time.
        if(!*first){
            //if the violation happens for first time.
            *first=*prev;
            *mid=root;
        }
        else{
            *last=root;
        }
    }
    *prev=root;
    calcPointers(root->right, first, mid, last, prev);
}

void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void restoreBST(Node* root){
    Node* first, *mid, *last, *prev; //here prev is basically used as a temp pointer.
    first=NULL;
    mid=NULL;
    last=NULL;
    prev=NULL;

    calcPointers(root, &first, &mid, &last, &prev);
    //case 1:
    if(first and last){
        //if first and last are not null.
        swap(&(first->data), &(last->data));
    }
    else if(first and mid){
        swap(&(first->data), &(mid->data));
    }
}

void inorder(Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){
    /*
    we create a voilated bst
                6
               / \
              9   3
             / \   \
            1   4   13  
    */
    Node* root=new Node(6);
    root->left=new Node(9);
    root->right=new Node(3);
    root->left->left= new Node(1);
    root->left->right= new Node(4);
    root->right->right= new Node(13);

    inorder(root);
    cout<<endl;
    restoreBST(root);
    inorder(root);
    return 0;
}