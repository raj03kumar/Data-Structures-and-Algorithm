#include<bits/stdc++.h>
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

Node* insertBST(Node* root, int val){

    if(root==NULL){
        return new Node(val);
    }
    if(val<root->data){
        root->left=insertBST(root->left, val);
    }else{
        //if val>root->data
        root->right=insertBST(root->right, val);
    }
    return root;
}   

void inorderTraversal(Node* root){
    if(root==NULL){
        return;
    }
    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}

int main(){
    Node* root=NULL;
    root=insertBST(root, 5);
    int arr[]={5,1,3,4,2,7};
    for(int i=1; i<sizeof(arr)/sizeof(arr[0]); i++){
        insertBST(root, arr[i]);
    }
    //now we do inorder traversal. NOTE: inorder of BST gives sorted array.

    inorderTraversal(root);
    return 0;
}