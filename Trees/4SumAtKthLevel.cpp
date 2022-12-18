// to find the sum of nodes at kth level in a binary tree.
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

int sumAtK(Node* root, int k){
    if(root==NULL){
        return -1;
    }

    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    int level=0;
    int sum=0;

    while(!q.empty()){
        Node* node=q.front();
        q.pop();

        if(node!=NULL){
            if(level==k){
                sum+=node->data;
            }
            if(node->left){
                q.push(node->left);
            }
            if(node->right){
                q.push(node->right);
            }
        }
        else if(!q.empty()){
            q.push(NULL);
            level++;
        }

    }

    return sum;
}

int main(){
    int postorder[]={4,2,5,3,1};
    int inorder[]={4,2,1,5,3};

    //build tree
    Node* root= buildTree(postorder, inorder, 0, 4);
    cout<<sumAtK(root, 1);

    return 0;
}
