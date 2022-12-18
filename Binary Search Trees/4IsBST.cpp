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

//check for bst
bool isBST(Node* root, Node* min=NULL, Node* max=NULL){
    //base case:
    if(root==NULL){
        return true;
    }
    if(min!=NULL and root->data<=min->data){
        return false;
    }
    if(max!=NULL and root->data>=max->data){
        return false;
    }
    //now we check for left subtree and right subtree
    bool leftValid=isBST(root->left, min, root);
    bool rightValid=isBST(root->right, root, max);
    //if both the trees are valid then we return true

    return leftValid and rightValid;

}

int main(){
    /*
            5
           / \
          2   6
    */
   Node*root=new Node(5);
   root->left=new Node(2);
   root->right=new Node(6);

   cout<<isBST(root,NULL, NULL);
   //This is valid bst

    return 0;
}