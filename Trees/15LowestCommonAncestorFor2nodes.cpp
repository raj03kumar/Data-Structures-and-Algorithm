#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node*left, *right;
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

bool getPath(Node* root, int key, vector<int> &path){
    //base case:
    if(root==NULL){
        return false;
    }

    path.push_back(root->data);
    if(root->data==key){
        return true;
    }

    if(getPath(root->left, key, path) or getPath(root->right, key, path)){
        return true;
    }
    path.pop_back();
    return false;
}

int LCA(Node* root, int n1, int n2){
    //we make path for both the nodes starting from root.
    vector<int> path1, path2;

    if(!getPath(root, n1, path1) or !getPath(root, n2, path2)){
        return -1; //if we were not able to find any path for both the nodes.
    }
    //note: at the common acestor our path changes. so we use this concept
    int pc; //path change
    for(pc=0; pc<path1.size() and path2.size(); pc++){
        if(path1[pc]!=path2[pc]){
            break;
        }
    }
    return path1[pc-1];
}
//new strategy
/*
In the above strategy we are doing operations in O(n) but we are traversing our tree many times. But in the new strategy we are doing traversal of any node only once.
*/


Node* LCA2(Node* root, int n1, int n2){
    if (root==NULL){
        return NULL;
    }
    if(root->data==n1 or root->data==n2){
        return root;
    }
    Node* left=LCA2(root->left, n1, n2);
    Node* right=LCA2(root->right, n1, n2);

    if(left!=NULL and right!=NULL){
        //this represent we have found either of n1 or n2 in either left or right
        return root;
    }
    //if LCA doesnt get found
    if(left==NULL and right==NULL){
        return NULL;
    }
    if(left!=NULL){
        return left;
    }
    return right;
}

int main(){
    /*
                1
               / \
              2   3
             /   / \
            4   5   6
               /
              7
    */

    Node *root = new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left= new Node(4);
    root->right->left=new Node(5);
    root->right->right=new Node(6);
    root->right->left->left=new Node(7);

    //let
    int n1=7;
    int n2=6;
    //we should get ans 3
    int lca= LCA(root, n1, n2);
    if(lca==-1){
        cout<<"LCA doesn't exist"<<endl;
    }
    else{
        cout<<"LCA: "<<lca<<endl;
    }


    Node* lca2=LCA2(root, n1, n2);
    if(lca2==NULL){
        cout<<"LCA doesn't exist"<<endl;
    }
    else{
        cout<<"LCA2: "<<lca<<endl;
    }
    return 0;
}
