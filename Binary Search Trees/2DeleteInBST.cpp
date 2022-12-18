// we have to make deletion in a BST now.
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

Node*inorderSucc(Node* root){
    Node* curr=root;
    while(curr and curr->left!=NULL){
        curr=curr->left;
    }
    return curr;
}

Node *deleteinBST(Node* root, int key){
    if (key<root->data){
        root->left=deleteinBST(root->left, key);
    }
    else if(key>root->data){
        root->right=deleteinBST(root->right, key);
    }
    else{
        if(root->left==NULL){
            Node* temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            Node* temp=root->left;
            free(root);
            return temp;
        }
        //case 3:
        Node* temp=inorderSucc(root->right);
        root->data=temp->data;
        root->right=deleteinBST(root->right, temp->data);
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
    
    inorderTraversal(root);
    cout<<"\nEnter the key you want to delete : ";
    int key; cin>>key;
    root=deleteinBST(root, key);
    inorderTraversal(root);
    return 0;
}