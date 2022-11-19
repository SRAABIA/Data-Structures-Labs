/*
Task-2: Implement main.cpp for the code provided such that a given array is passed to form a BST{15,
10, 20, 8, 12, 16, 25 }
*/
#include<iostream>
#include<queue>
#define space 10
using namespace std;

class node{
    public:
    int key;
    node* left;
    node* right;
    node(){
        key = 0;
        left = NULL;
        right = NULL;
    }
    node(int k){
        key = k;
        left  = NULL;
        right = NULL;
    }
};
class BST{
    public:
    node* root;
    BST(){
    root = NULL;
    }
    bool isTreeEmpty() {
    if (root == NULL) {
      return true;
    } else {
      return false;
    }
  }
    node* insertNode(node*r, node* nnode){
        if(r == NULL){
            root = nnode;
            cout << "Inserted node: " <<nnode->key<<endl;
            return root;
        }
        if(nnode->key < r->key){
            r->left = insertNode(r->left,nnode);
        }
        else if(nnode->key > r->key){
            r->right = insertNode(r->right,nnode);
        }
        else{
            cout<<endl<<"Duplicate values are not accpeted in BST"<<endl;
            return r;
        }
        return r;
    }
    void print(node*r,int sp){
        if(r==NULL) return;
        sp+=space;
        print(r->right,sp);
        cout<<endl;
        for(int i=0;i<sp;i++){
            cout<<" ";
        }
        cout<<r->key<<endl;
        print(r->left,sp);
    }

};
int main(){
    int k,p;
    BST tree;
    int*arr = new int[7]{15,10,20,8,12,16,25};
    do{
    cout<<endl
    <<"0. exit"<<endl
    <<"1. Convert Array to BST"<<endl
    <<"2. Print the tree"<<endl
    <<":: ";
    cin>>k;
    switch (k)
    {
    case 1:
        for(int i = 0; i< 7; i++){
        node*n = new node();
        n->key = arr[i];
        tree.root = tree.insertNode(tree.root,n);
        }
        break;
    case 2:
        tree.print(tree.root,5);
        break;
    }
    }while(k!=0);
}