#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left; 
    Node* right;
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
}; 

int maxPathSumUtil(Node* root, int &ans){
    if(root==NULL) {
        return 0;
    }
    int left=maxPathSumUtil(root->left, ans);
    int right=maxPathSumUtil(root->right, ans);

    int nodeMax=max(max(root->data, root->data+left+right), 
                    max(root->data+left, root->data+right));
    ans=max(ans, nodeMax);
    int singlePathSum=max(root->data, max(root->data + left, root->data + right));
    return singlePathSum;
}

int maxPathSum(Node* root){
    int ans= INT_MIN;
    maxPathSumUtil(root, ans);  //this part is very important we have to pass the address of ans and not the ans.
    return ans;
}

int main(){
    /*
    BINARY TREE:
            1
          /   \
         2     3
        /       \   
       4         5  
    */
    // Node* root=new Node(1);
    // root->left=new Node(2);
    // root->right= new Node(3);
    // root->left->left= new Node(4);
    // root->right->right= new Node(5);

    /*
    BINARY TREE:
            4
          /   \
         9     5
        /  \   /
       1   3  6
    */
    Node* root=new Node(4);
    root->left=new Node(9);
    root->right= new Node(5);
    root->left->left= new Node(1);
    root->left->right= new Node(3);
    root->right->right= new Node(6);

    //test
    cout<<maxPathSum(root);
    //ans is 15.
    return 0;
}