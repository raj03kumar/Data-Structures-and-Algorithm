// to find whether the tree is balanced or not.
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

int findHeight(Node* root){
    if(root==NULL){
        return 0;
    }
    return max(findHeight(root->left),findHeight(root->right))+1;
}

bool isBalanced(Node* root){
    if(root==NULL){
        return true;
    }
    if(isBalanced(root->left)==false){
        return false;
    }
    if(isBalanced(root->right)==false){
        return false;
    }

    int leftHeight=findHeight(root->left);
    int rightHeight=findHeight(root->right);
    if(abs(leftHeight-rightHeight)<=1){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    int postorder[]={4,2,5,3,1};
    int inorder[]={4,2,1,5,3};

    //build tree
    Node* root= buildTree(postorder, inorder, 0, 4);

    //height balanced BT
    if(isBalanced(root)==true){
        cout<<"Balanced BT\n";
    }
    else{
        cout<<"Not Balanced BT\n";
    }

    return 0;
}