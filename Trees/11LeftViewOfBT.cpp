// we have to see our BT from left side.

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

void leftView(Node* root){
    if(root==NULL){
        return;
    }
    //now we have to do level order traversal so we make queue.
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        int n=q.size(); //checks how many nodes are there in queue.
        for(int i=0; i<n; i++){
            Node* curr=q.front();
            q.pop();

            if(i==0){
                //then we print the data. which is the last element in the current level
                cout<<curr->data<<" ";
            }

            if(curr->left!=NULL){
                q.push(curr->left);
            }
            if(curr->right!=NULL){
                q.push(curr->right);
            }
        }
    }
}

int main(){
    int postorder[]={4,2,5,3,1};
    int inorder[]={4,2,1,5,3};

    //build tree
    Node* root= buildTree(postorder, inorder, 0, 4);
    // inorderTraversal(root);

    leftView(root);

    return 0;
}