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

Node* sortedArrayToBST(int arr[], int start, int end){
    //base condition:
    if(start>end){
        return NULL;
    }
    
    int mid=(start+end)/2;
    Node* root=new Node(arr[mid]);

    root->left=sortedArrayToBST(arr, start, mid-1);
    root->right=sortedArrayToBST(arr, mid+1, end);

    return root;
}

void preorderTraversal(Node*root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main(){
    int arr[]={1,2,3,4,5,6,7,8};
    Node* root=sortedArrayToBST(arr, 0, 7);
    preorderTraversal(root);
    return 0;
}