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

// isIdentical
bool isIdentical(Node* root1, Node* root2){
    if(root1==NULL and root2==NULL){
        return true;
    }
    else if(root1==NULL or root2==NULL){
        return false;
    }
    else{
        bool cond1=root1->data==root2->data;
        bool cond2=isIdentical(root1->left, root2->left);
        bool cond3=isIdentical(root1->right, root2->right);

        if(cond1 and cond2 and cond3){
            return true;
        }
        else{
            return false;
        }
    }
}

int main(){
    /*
                12
               /  \
              9    15
             / \
            5   10
    */

    Node* root=new Node(12);
    root->left=new Node(9);
    root->right= new Node(15);
    root->left->left= new Node(5);
    root->left->right= new Node(10);

    cout<<isIdentical(root, root);      //returns true.
    return 0;
}   