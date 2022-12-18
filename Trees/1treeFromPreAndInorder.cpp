/*
Algorithm:
1. pick element from preorder and create a node.
1. increment preorder idx
3. Search for picked elements pos in inorder.
4. Call to build left subtree from inorder position 0 to pos-1.
5. Call to build right subtree from inorder postition pos+1 to n;
6. return the node
*/
#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int value){
        //this is the constructor
        data=value;
        left=NULL;
        right=NULL;
    }
};

int search(int inorder[], int start, int end, int curr){
    for(int i=start; i<=end; i++){
        if(inorder[i]==curr){
            return i;
        }
    }
    return -1;
}

Node* buildTree(int preorder[], int inorder[], int start, int end){
    static int idx=0;
    //base condition:
    if(start>end){
        return NULL;
    }
    int curr=preorder[idx];
    idx++;
    Node* node= new Node(curr);
    if(start==end){
        //means only one node is there
        return node;
    }
    //now we find the postion of current in inorder traversal
    int pos=search(inorder, start, end, curr);
    //now we recursively build the left and righ tsubtree
    node->left=buildTree(preorder, inorder, start, pos-1);
    node->right=buildTree(preorder, inorder, pos+1, end);

    return node;
}

void inorderTraversal(Node* root){
    if(root==NULL){
        return ;
    }
    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}

int main(){
    int preorder[]={1,2,4,3,5};
    int inorder[]={4,2,1,5,3};

    //build tree
    Node* root= buildTree(preorder, inorder, 0, 4);
    inorderTraversal(root);
    return 0;
}