#include<bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    Node*left, *right;
};

Node* newNode(int key){
    Node* node= new Node;
    node->key=key;
    node->left=node->right=NULL;

    return node;
}

void getVerticalOrder(Node* root, int hdis, map<int, vector<int>> &m){
    if(root==NULL){
        return; 
    }
    m[hdis].push_back(root->key);
    getVerticalOrder(root->left, hdis-1, m);
    getVerticalOrder(root->right, hdis+1, m);
}

int main(){
    Node *root=newNode(10);
    root->left=newNode(7);
    root->right=newNode(4);
    root->left->left=newNode(3);
    root->left->right=newNode(11);
    root->right->left=newNode(14);
    root->right->right=newNode(6);

    map<int, vector<int>>m;
    int hDis=0;

    getVerticalOrder(root, hDis, m);

    map<int, vector<int>> :: iterator it;

    for(it=m.begin(); it!=m.end(); it++){
        for(int i=0; i<(it->second).size(); i++){
            cout<<(it->second)[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}