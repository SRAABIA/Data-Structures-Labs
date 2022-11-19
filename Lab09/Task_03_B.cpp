#include<iostream>
using namespace std;
#include<stack>
class node{
    public:
    int key;
    node* left;
    node* right;
    node(){
        key=0;
        left = NULL;
        right = NULL;
    }
    node(int k){
        key = k;
        left = NULL;
        right = NULL;
    }
};
class BST{
    public:
    node* root;
    BST(){
        root = NULL;
    }
    node* Insert(node*r,node* n){
        if(r==NULL) {
            r = n;
        }
        else if(n->key < r->key){
            r->left = Insert(r->left,n);
        }
        else if(n->key > r->key){
            r->right = Insert(r->right,n);
        }
        else{
            cout<<endl<<"\tError! Duplicate Values Not Acceptible in BST.";
        }
        return r;
    }
    void Preorder(node*r){
        //nlr
        if(r==NULL) return;
        cout<<" "<<r->key;
        Preorder(r->left);
        Preorder(r->right);
    }
    void Inorder(node* r){
        //lnr
        stack<node*> s;
        if(r==NULL) return;
        node*current = r;
        while(current!= NULL || !s.empty()){
            while(current!= NULL){
                s.push(current);
                current = current->left;
            }
            if(current == NULL){
                node* temp = s.top();
                cout<<" "<<temp->key;
                current = temp->right;
                s.pop();
            }
        }
    }

};

int main(){
    int k,m;
    BST obj;
    do{
        cout<<endl
        <<"\tBinary Search Tree"<<endl
        <<"\t0. Exit"<<endl
        <<"\t1. Insert"<<endl
        <<"\t2. Inorder(Iterative)"<<endl
        <<"\t3. Preorder(Recursive)"<<endl
        <<"\t:: ";
        cin>>k;
        node* tt = new node();
        switch(k){
            case 1:
                cout<<endl<<"\tEnter a key for new node: "; cin>>tt->key;
                obj.root = obj.Insert(obj.root,tt);
            break;
            case 2:
            	cout<<endl<<"\tPrinting Inorder: "<<endl<<"\t";
                obj.Inorder(obj.root);
            break;
            case 3:
            	cout<<endl<<"\tPrinting Preorder: "<<endl<<"\t";
                obj.Preorder(obj.root);
            break;
        }
    }while(k!=0);

}