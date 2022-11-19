/*
Build functionality named autoGrader which will assist DS teacher to check students BST
assignments such that if given tree is BST assign 10 points if not then assign 0.
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
    node* insertNode(node*r, node* newnode){ //in bt fashion
        if(r == NULL){
            root = newnode;
            cout << "Value Inserted as root node!" << endl;
            return root;
        }
        node*temp = NULL;
        queue<node*>q;
        q.push(r);
        while(!q.empty()){
            temp  = q.front();
            q.pop();
            if(temp->left == NULL){
                temp->left = newnode;
                cout<<endl<<"Left node inserted";
                return r;
            }
            if(temp->right == NULL){
                temp->right = newnode;
                cout<<endl<<"Right node inserted";
                return r;
            }
            else{
                q.push(temp->left);
                q.push(temp->right);
            }
        }
        return r;
    }

    bool isBSt(node*r ,int min,int max){
        if(r==NULL) return true;
        if(r->key < min || r->key>max ) return false;
        return isBSt(r->left,min,r->key) && isBSt(r->right,r->key,max);
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
    int autoGrader(node*r){
        if(isBSt(r,INT8_MIN,INT8_MAX)) return 10;
        else return 0;
    }
};
int main(){
    int k,p;
    BST tree;
    do{
        node*n = new node();
    cout<<endl
    <<"0. exit"<<endl
    <<"1. Insert in binary tree"<<endl
    <<"2. Check if given tree is BST"<<endl
    <<"3. Print the tree"<<endl
    <<":: ";
    cin>>k;
    switch (k)
    {
    case 1:
        cout<<endl<<"Enter Value: "; 
        cin>>n->key;
        tree.root = tree.insertNode(tree.root,n);
        break;
    case 2:
        cout<<endl<<"Checking if the given tree is bst....?";
        cout<<endl<<endl<<"Your marks for creating BST are: "<<tree.autoGrader(tree.root)<<endl;
        break;
    case 3:
        tree.print(tree.root,5);
        break;
    }
    }while(k!=0);
}