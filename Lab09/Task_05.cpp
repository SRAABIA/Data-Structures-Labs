/*
Task: 5:
Assume that a given binary tree stores integer values in its nodes. Write a recursive function that
traverses a binary tree and prints the value of every node who’s parent has a value that is a
multiple of five. The function should be implemented in the main program.
*/
#include<iostream>
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
    
    void Multiple_5(node*r){
        //nlr
        if(r==NULL) return;
        if(r->key % 5 == 0 ){
             cout<<endl;
            if(r->left!=NULL){
                cout<<" "<<r->left->key;
            }
            if(r->right!=NULL){
                cout<<" "<<r->right->key;
            }
        } 
        Multiple_5(r->left);
        Multiple_5(r->right);   
    }
    void Preorder(node*r){
        //nlr
        if(r==NULL) return;
        cout<<" "<<r->key;
        Preorder(r->left);
        Preorder(r->right);
    }

};
int main(){
    int k,p;
    BST tree;
    int r_1;
    int*arr = new int[16]{15,10,20,8,12,16,25,35,32,84,72,76,95,94,100,150};
    do{
    cout<<endl
    <<"0. exit"<<endl
    <<"1. Convert Array to BST"<<endl
    <<"2. Preorder"<<endl
    <<"3. Print Tree"<<endl
    <<"4. Multiple_5"<<endl
    <<":: ";
    cin>>k;
    switch (k)
    {
    case 1:
        for(int i = 0; i< 16; i++){
        node*n = new node();
        n->key = arr[i];
        tree.root = tree.insertNode(tree.root,n);
        }
        break;
    case 2:
        tree.Preorder(tree.root);
        break;
    case 3:
        tree.print(tree.root,2);
        break;    
    case 4:
        cout<<endl<<"These keys have parents multiple of 5:"<<endl<<"\t"; 
        tree.Multiple_5(tree.root);
        break;
    }
    }while(k!=0);
}