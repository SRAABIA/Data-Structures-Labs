/*
Task-3:
A. Write recursive algorithms that perform preorder and inorder ,postorder tree
walks.
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

    void Preorder(node*r){
        //nlr
        if(r==NULL) return;
        cout<<" "<<r->key;
        Preorder(r->left);
        Preorder(r->right);
    }
    void inorder(node*r){
        //lnr
        if(r==NULL) return;
        inorder(r->left);
        cout<<" "<<r->key;
        inorder(r->right);
    }
    void postorder(node*r){
        //lrn
        if(r==NULL) return;
        postorder(r->left);
        postorder(r->right);
        cout<<" "<<r->key;
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
    <<"2. Preorder"<<endl
    <<"3. Inorder"<<endl
    <<"4. Postorder"<<endl
    <<"5. Print Tree"<<endl
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
        tree.Preorder(tree.root);
        break;
    case 3:
        tree.inorder(tree.root);
        break;
    case 4:
        tree.postorder(tree.root);
        break;
    case 5:
        tree.print(tree.root,5);
        break;    
    }
    }while(k!=0);
}