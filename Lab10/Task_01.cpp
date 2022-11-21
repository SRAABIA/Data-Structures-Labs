/*
Task:1
Construct BST: {10,20,30,40,50,45} after construction, write a function to check that
constructed BST are balanced or not?
*/
#include<iostream>
using namespace std;
#define spaces 10
class Tree{
    public:
    int key;
    Tree* left;
    Tree* right;
    Tree(){
        key=0;
        left=right=NULL;
    }
    Tree(int k){
        key=k;
        left=right=NULL;
    }
};

class BST{
    public:
    Tree *root;
    BST(){
        root=NULL;
    }
    int height(Tree*r){
        if(r==NULL){
            return -1;
        }
        int lheight = height(r->left);
        int rheight = height(r->right);

        if(lheight>rheight) return lheight+1;
        else return rheight + 1;
    }

    int get_Balanced_Factor(Tree*r){
        if(r == NULL){ return -1;
        }
        return height(r->left) - height(r->right);
    }

    Tree* rightrotate(Tree* r){
        Tree*x = r->left;
        Tree*y = x->right;
        x->right = r;
        r->left = y;
        return x;    
    }
    Tree* leftrotate(Tree* r){
        Tree* x = r->right;
        Tree* y = x->left;
        x->left = r;
        r->right = y;
        return x;
    }
    Tree* insert(Tree*r, Tree*node){
        if(r==NULL) {
            r= node;
            cout<<"Inserted node."<<r->key<<endl;
            return r;
        }
        if(node->key<r->key){
            r->left = insert(r->left, node);
        }
        else if(node->key>r->key){
            r->right = insert(r->right,node);
        }
        else{
            cout<<"No duplicate values allowed."<<endl;
            return r;
        }
        // int bf = get_Balanced_Factor(r);
    }

    void printTree(Tree* r, int sp){
        if(r == NULL) return;
        sp+= spaces;
        printTree(r->right,sp);
        cout<<endl;
        for(int i = 0 ; i < sp; i++){
            cout<<" ";
        }
            cout<<r->key<<endl;
            printTree(r->left,sp);
        
    }

    bool inorder(Tree*r){
        if(r==NULL) {
            return 0;
        }
        inorder(r->left);
        if(get_Balanced_Factor(r)>1 || get_Balanced_Factor(r)<-1){
            return 1;
        }
        inorder(r->right);
    }
    

};
int main(){
    BST obj;
    int n,k;
    int m;
    int arr[6] = {10,20,30,40,50,45};
    for(int i=0;i<6;i++){
    Tree*node=new Tree();
    node->key = arr[i];
        obj.root = obj.insert(obj.root,node);
    }
    if(obj.inorder(obj.root)){
        cout<<"This tree is not balanced";

    }
    else{
        cout<<"This tree is balanced";
    }
    obj.printTree(obj.root,10);
}