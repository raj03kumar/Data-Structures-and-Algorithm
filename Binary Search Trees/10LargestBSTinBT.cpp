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

struct Info{
    int size;
    int max;
    int min;
    int ans;
    bool isBST;
};

Info largestBSTinBT(Node* root){
    if(root==NULL){
        return {0, INT_MIN, INT_MAX, 0, true};
    }
    //single node is always a BST.
    if(root->left==NULL and root->right==NULL){
        return {1, root->data, root->data, 1, true};
    }
    Info leftInfo=largestBSTinBT(root->left);
    Info rightInfo=largestBSTinBT(root->right);

    Info curr;
    curr.size=(1+leftInfo.size+rightInfo.size);

    if(leftInfo.isBST and rightInfo.isBST and leftInfo.max<root->data and rightInfo.min>root->data){
        curr.min=min(leftInfo.min, min(rightInfo.min, root->data));
        curr.max=max(rightInfo.max, max(leftInfo.max, root->data));

        curr.ans=curr.size;
        return curr;
    }

    curr.ans=max(leftInfo.ans, rightInfo.ans);
    curr.isBST=false;
    return curr;
}

int main(){
    /*
            15
           /  \
          20  30
         /
        5
    */
    Node* root= new Node(15);
    root->left=new Node(20);
    root->right=new Node(30);
    root->left->left=new Node(5);

    cout<<"Largest BST IN BT: "<<largestBSTinBT(root).ans<<endl;
    return 0;
}