// we have to make search in a bst now.
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

Node* searchBST(Node* root, int key){
    if(root==NULL){
        return NULL;
    }

    if(root->data==key){
        return root;
    }
    if(root->data>key){
        return searchBST(root->left, key);
    }

    return searchBST(root->right, key);
}

int main(){
    Node* root=NULL;
    root=insertBST(root, 5);
    int arr[]={5,1,3,4,2,7};
    for(int i=1; i<sizeof(arr)/sizeof(arr[0]); i++){
        insertBST(root, arr[i]);
    }
    
    cout<<"Enter the key you want to search: ";
    int key; cin>>key;
    if(searchBST(root, key)==NULL){
        cout<<"Key doesn't exist\n";
    }
    else{
        cout<<"key exist\n";
    }

    return 0;
}