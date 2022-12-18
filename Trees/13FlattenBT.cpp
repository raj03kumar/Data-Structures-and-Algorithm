//we have to flatten a BT into a linked list without using any other data structure

//NOTE: Simple understanding. we have to leave the left subtree as it is. we have to append the right subtree to the left subtree to its last node. then recursively we have to do this only.
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left; Node* right;
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

void flatten(Node* root){

    if(root==NULL or (root->left==NULL and root->right==NULL)){
        //means tree is already flattened.
        return;
    }
    if(root->left!=NULL){
        flatten(root->left);

        Node* temp= root->right;
        root->right=root->left;
        root->left=NULL;

        //now we have to calculate the tail or right subtree
        Node* t=root->right;
        while(t->right!=NULL){
            t=t->right;
        }
        //note: t is the right subtree tail. 

        t->right=temp;
    }
    flatten(root->right);
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
    Node* root=new Node(4);
    root->left=new Node(9);
    root->right= new Node(5);
    root->left->left= new Node(1);
    root->left->right= new Node(3);
    root->right->right= new Node(6);
    /*
    BINARY TREE:
            4
          /   \
         9     5
        /  \   /
       1   3  6
    */
    
    flatten(root);
    inorder(root);
    //ans: 4 9 1 3 5 6
    return 0;
}