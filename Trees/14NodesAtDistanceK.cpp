// we have to find and print all the nodes at distance k.
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

//case 1:
void printSubTreeNodes(Node* root, int k){
    if(root==NULL or k<0){
        return;
    }
    if(k==0){
        cout<<root->data<<" ";
        return;
    }
    printSubTreeNodes(root->left, k-1);
    printSubTreeNodes(root->right, k-1);
}

//case 2:
int printNodesatK(Node* root, Node* target, int k){
    if(root==NULL){
        return -1;
    }
    if(root==target){
        printSubTreeNodes(root, k);
        //we now return the distance which is 0. because we have found out target ancestor
        return 0;
    }
    //we now find dl and dr which is distance_left and distance_right
    int dl=printNodesatK(root->left,target, k);
    if(dl!=-1){
        if(dl+1==k){
            cout<<root->data<<" ";
        }
        else{
            //if our target is on left subtree then we find in the right subtree.
            printSubTreeNodes(root->right, k-dl-2);
        }
        return 1+dl;
    }
    //same we do for right subtree.
    int dr=printNodesatK(root->right, target,k);
    if(dr!=-1){
        if(dr+1==k){
            cout<<root->data<<" ";
        }
        else{
            //if our target is on left subtree then we find in the right subtree.
            printSubTreeNodes(root->left, k-dr-2);
        }
        return 1+dr;
    }

    return -1;
}

int main(){
    /*
                1
               / \
              2   3
             /
            4   
    */
    Node * root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left= new Node(4);
    //test
    //we are passing to find the nodes at distance 1 from 2.
    printNodesatK(root, root->left, 1);
    // ans = 4 1.
    return 0;
}