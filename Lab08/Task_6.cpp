#include<iostream>
#include<stdio.h>
#include<queue>
#define spaces 10
using namespace std;
class Node {
	public:
		int key;
		Node *left;
		Node* right;
		Node() {
			key = 0;
			right = left = NULL;
		}
		Node(int k) {
			key = k;
			left = right =NULL;
		}
};
class BinaryTree {
	public:
		Node*root;
		BinaryTree() {
			root = NULL;
		}

		void print(Node*r, int sp) {
			if(r==NULL)
				return;
			sp+=spaces;
			print(r->right,sp);
			cout<<endl;
			for(int i=0; i<sp; i++) {
				cout<<" ";
			}
			cout<<r->key<<endl;
			print(r->left,sp);
		}

		Node* inserting(Node*r, Node*n) {
			if(r==NULL) {
				root = n;
				return r;
			}
			Node* temp = NULL;
			queue<Node*>q;
			q.push(r);
			while(!q.empty()) {
				temp = q.front();
				q.pop();
				if(temp->left == NULL) {
					if(temp->key != -1) {
						temp->left = n;
						printf("\nLeft Node Inserted.");
						return r;
					}
				} 
				if(temp->right==NULL) {
					if(temp->key != -1) {
						temp->right = n;
						printf("\nRight Node Inserted.");
						return r;
					}
				} else {
					q.push(temp->left);
					q.push(temp->right);
				}
			}
			return r;
		}
	
		void inorder(Node*r){
			if (r==NULL) return;
			inorder(r->left);
			cout<<"  "<<r->key;
			inorder(r->right);
		}
		void postorder(Node*r){
			if (r==NULL) return;
			postorder(r->left);
			postorder(r->right);
			cout<<"  "<<r->key;
		}
		void preorder(Node*r){
			if (r==NULL) return;
			cout<<"  "<<r->key;
			preorder(r->left);
			preorder(r->right);
		}
};	
int main() {
	BinaryTree tree;
	int i,k;
	do {
		Node*node = new Node();
		cout<<endl<<endl<<"Choose one option: ";
		cout<<endl<<"0. Exit"
		    <<endl<<"1. Insert"
		    <<endl<<"2. Print"
		    <<endl<<"3. Inorder"
		    <<endl<<"4. Postorder"
		    <<endl<<"5. Preorder"
		    <<endl<<"::  ";
		cin>>i;
		switch(i) {
			case 0:
				return 0;
				break;
			case 1:
				cout<<endl<<"Enter the value of node: ";
				cin>>node->key;
				tree.inserting(tree.root,node);
				break;
			case 2:
				printf("\nTree Printing: \n");
				tree.print(tree.root,4);
				break;
			case 3:
				printf("\nInorder Printing\n");
				tree.inorder(tree.root);
				break;
			case 4:
				printf("\nPostorder Printing\n");
				tree.postorder(tree.root);
				break;
			case 5:
				printf("\nPreorder Printing\n");
				tree.preorder(tree.root);
				break;
	} 
	}while(i!=0);
}