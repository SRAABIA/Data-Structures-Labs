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
        cout <<endl <<"\t["<< r -> key << "] BF: "<<get_Balanced_Factor(r);
        inorder(r->right);
    }

    Tree * minValueNode(Tree * node) {
        Tree * current = node;
        while (current -> left != NULL) {
            current = current -> left;
        }
        return current;
    }

    Tree * deleteNode(Tree * r, int v) {
        // base case
        if (r == NULL) {
            return NULL;
        } else if (v < r ->key) {
            r -> left = deleteNode(r -> left, v);
        } else if (v > r ->key) {
            r -> right = deleteNode(r -> right, v);
        } else {
            if (r -> left == NULL) {
                Tree * temp = r -> right;
                delete r;
                return temp;
            } else if (r -> right == NULL) {
                Tree * temp = r -> left;
                delete r;
                return temp;
            } else {
                Tree * temp = minValueNode(r -> right);
                r -> key= temp -> key;
                r -> right = deleteNode(r -> right, temp -> key);
            }
        }

        int bf = get_Balanced_Factor(r);
        if (bf == 2 && get_Balanced_Factor(r -> left) >= 0)
            return rightrotate(r);
        else if (bf == 2 && get_Balanced_Factor(r -> left) == -1) {
            r -> left = leftrotate(r -> left);
            return rightrotate(r);
        } else if (bf == -2 && get_Balanced_Factor(r -> right) <= 0)
            return leftrotate(r);
        else if (bf == -2 && get_Balanced_Factor(r -> right) == 1) {
            r -> right = rightrotate(r -> right);
            return leftrotate(r);
        }

        return r;
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
    cout<<"Tree before Deletion:"<<endl<<endl;
    obj.printTree(obj.root,10);
    //deleting nodes from AVL
    obj.deleteNode(obj.root,35);
    obj.deleteNode(obj.root,99);
    cout<<endl<<endl<<"Tree after Deletion:"<<endl<<endl;
    obj.printTree(obj.root,10);
    
}