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

Node* constructBST(int preorder[], int *preorderIdx, int key, int min, int max, int n){
    //base condition:
    if(*preorderIdx>=n){
        return NULL;
    }

    Node* root=NULL;
    if(key>min and key<max){
        root= new Node(key);
        //now we update the preorder index
        *preorderIdx=*preorderIdx+1;

        if(*preorderIdx<n){
            root->left=constructBST(preorder, preorderIdx, preorder[*preorderIdx], min, key, n);
        }
        //we check if still it is less than n. then we build root->right
        if(*preorderIdx<n){
            root->right=constructBST(preorder, preorderIdx, preorder[*preorderIdx], key, max, n);
        }
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
    /*
                10
               /  \
              2   13
             /    / 
            1    11
    */

    int preorder[]={10, 2, 1, 13, 11};
    int n=5;
    int preorderIdx=0;
    Node *root = constructBST(preorder, &preorderIdx, preorder[0], INT_MIN, INT_MAX, n);

    inorderTraversal(root);     //should give a sorted array.
    return 0;
}   