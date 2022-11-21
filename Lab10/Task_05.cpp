/*
Task:3
Delete the nodes 35 and 99 from the tree, recalculate the bf and perform rotations to
balance the tree.
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
class AVL{
    public:
    Tree* root;
    AVL(){
        root = NULL;
    }
    int height(Tree*r){
        if(r==NULL){
            return -1;
        }
        else{
        int lheight = height(r->left);
        int rheight = height(r->right);

        if(lheight>rheight) return lheight+1;
        else return rheight + 1;
        }
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
            cout<<"Inserted node."<<endl;
            return r;
        }

        if(node->key < r->key){
            r->left = insert(r->left, node);
        }
        else if(node->key > r->key){
            r->right = insert(r->right,node);
        }
        else{
            cout<<"No duplicate values allowed."<<endl;
            return r;
        }
       
        int bf = get_Balanced_Factor(r);
        // cout<<"\nBalance Factor before rotation of node ["<<r->key<<"] is : "<<bf;
        if(bf>1 && node->key < r->left->key){
            return rightrotate(r);
            //left left imbalancing
            //rightrotation
        }
        if(bf<-1 && node->key > r->right->key){
            //right right imbalancing
            // left rotation
            return leftrotate(r);
        }
        if(bf>1 && node->key > r->left->key){
            // right left imbalancing
            // left right rotate
            r->left = leftrotate(r->left);
            return rightrotate(r);
        }
        if(bf<-1 && node->key < r->right->key){
            //left right imbalancing
            // right left rotate
            r->right = rightrotate(r->right);
            return leftrotate(r);
        }
        return r;
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

    void inorder(Tree*r){
        if(r==NULL) {
            return;
        }
        inorder(r->left);
        cout<<"\t["<< r -> key << "]";
        inorder(r->right);
    }
    void preorder(Tree*r){
        if(r==NULL) {
            return;
        }
        cout<<"\t["<< r -> key << "]";
        preorder(r->left);
        preorder(r->right);
    }
    void postorder(Tree*r){
        if(r==NULL) {
            return;
        }
        postorder(r->left);
        postorder(r->right);
        cout<<"\t["<< r -> key << "]";
    }
};
int main(){
    AVL obj;
    int n,k;
    int m;
    int arr[11] = {55,66,77,11,33,22,35,25,44,88,99};
    for(int i=0;i<11;i++){
    Tree*node=new Tree();
        node->key = arr[i];
        obj.root = obj.insert(obj.root,node);
    }
    cout<<"Tree Preorder"<<endl<<endl;
    obj.preorder(obj.root);
    cout<<endl<<"Tree Inorder"<<endl<<endl;
    obj.inorder(obj.root);
    cout<<endl<<"Tree Postorder"<<endl<<endl;
    obj.postorder(obj.root);   
    
}