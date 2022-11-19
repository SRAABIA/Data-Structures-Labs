/*
Task: 6:
Write a recursive function named smallcount that, given the pointer to the root of a BST and a
key K, returns the number of nodes having key values less than or equal to K. Function should
be implemented in the main program.
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
    
    int SmallCount(node*r,int& k){
        //nlr
        static int count;
        if(r==NULL) return count;
        if(r->key <= k ) count++;
        SmallCount(r->left,k);
        SmallCount(r->right,k);
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
    int r_1,r_2;
    int SmallCount(node*,int&); //function implementation
    int*arr = new int[7]{15,10,20,8,12,16,25};
    do{
    cout<<endl
    <<"0. exit"<<endl
    <<"1. Convert Array to BST"<<endl
    <<"2. Preorder"<<endl
    <<"3. Print Tree"<<endl
    <<"4. SmallCount"<<endl
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
        tree.print(tree.root,5);
        break;    
    case 4:
        cout<<endl<<"Enter Value of K: ";
        cin>>r_1;
        cout<<endl<<"Number of keys less than or equal to "<<r_1<<" is :"<<tree.SmallCount(tree.root,r_1);
        break;
    }
    }while(k!=0);
}