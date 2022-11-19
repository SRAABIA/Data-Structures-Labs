/*
Task:4
Given a BST and a range of keys(values), remove nodes from BST 
that have keys outside the given range
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
    

    node* minVAL(node* n){
        node* temp=n;
        while(temp->left!=NULL){
            temp=temp->left;
        }
        return temp;
    }
    node* deletenode(node*r,int v){
        if(r==NULL) return NULL;
        else if(v < r->key){
            r->left = deletenode(r->left,v);
        }
        else if(v > r->key){
            r->right = deletenode(r->right,v);
        }
        else{
            if(r->left == NULL){
                node* temp = r->right;
                delete r;
                return temp;
            }
            else if(r->right ==NULL){
                node* temp = r->left;
                delete r;
                return temp;
            }
            else{
                node*temp = minVAL(r->right);
                r->key = temp->key;
                r->right = deletenode(r->right,temp->key);
            }
        }
        return r;
    }
    void delete_bw_range(node*r,int&a, int&b){
        //nlr
        if(r==NULL) return;
        for(int i=a;i<=b;i++){
            r = deletenode(r,i);
        }
        delete_bw_range(r->left,a,b);
        delete_bw_range(r->right,a,b);
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
    int r_1,r_2;
    int*arr = new int[7]{15,10,20,8,12,16,25};
    do{
    cout<<endl
    <<"0. exit"<<endl
    <<"1. Convert Array to BST"<<endl
    <<"2. Preorder"<<endl
    <<"3. Inorder"<<endl
    <<"4. Postorder"<<endl
    <<"5. Print Tree"<<endl
    <<"6. Delete bw Range"<<endl
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
    case 6:
        cout<<endl<<"Enter Range digits: ";
        cin>>r_1>>r_2;
        tree.delete_bw_range(tree.root,r_1,r_2);
        break;
    }
    }while(k!=0);
}