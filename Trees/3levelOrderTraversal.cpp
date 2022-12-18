//cpp code for level order traversal.
#include<bits/stdc++.h>
using namespace std;

//here we use previous tree which we have made.
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

void inorderTraversal(Node* root){
    if(root==NULL){
        return ;
    }
    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}

Node* buildTree(int postorder[], int inorder[], int start, int end){
    static int idx=4;        //this is the last index of postorder.

    //base condition:
    if(start>end){
        return NULL;
    }

    int val=postorder[idx];
    idx--;
    Node* curr=new Node(val);
    if(start==end){
        return curr;
    }

    int pos=search(inorder, start, end, val);
    //now we build right subtree first.
    curr->right=buildTree(postorder, inorder, pos+1, end);
    curr->left=buildTree(postorder, inorder, start, pos-1);

    return curr;
}

void printLevelOrder(Node* root){
    if(root==NULL){
        return;
    }

    queue<Node* > q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* node=q.front();
        q.pop();
        if(node!=NULL){
            cout<<node->data<<" ";
            if(node->left){
                //we check if node->left is not equal to NULL.
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
        else if(!q.empty()){
            q.push(NULL);
        }
    }
}

int main(){
    int postorder[]={4,2,5,3,1};
    int inorder[]={4,2,1,5,3};

    //build tree
    Node* root= buildTree(postorder, inorder, 0, 4);
    // inorderTraversal(root);
    printLevelOrder(root);
    return 0;
}