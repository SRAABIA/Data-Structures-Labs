#include<iostream>
using namespace std;
class Node{
    public:
        int key;
        int data;
        Node* prev;
        Node* next;
        Node() {
            key = 0;
            data = 0;
            next = NULL;
            prev = NULL;
        }
        Node(int k, int d) {
            key = k;
            data = d;
            next = NULL;
            prev = NULL;
        }
};
class Doubly{
    public:

    Node* head;
    Node* tail;
    Doubly(){
        head = NULL;
        tail = NULL;
    }
    Doubly(Node*n){
        head = n;
        Node*temp = NULL;
        Node*ptr = head;
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        tail = ptr;
    }
    Node* exist(int k){
        Node*temp = NULL;
        Node*ptr = head;
        while(ptr!=NULL){
            if(ptr->key == k){
                temp = ptr;
            }
            ptr=ptr->next;
        }
        return temp;
    }

    bool Append(int k,int d){
        if(exist(k) != NULL){
            cout<<"Node with key ["<<k<<"] already exists."<<endl;
            return false;
        }
        else{
            Node* p = new Node(k,d);
            if(head==NULL){
                head = p;
                tail = p;
                cout<<"Node Appended."<<endl;
            }
            else{
                Node*temp=head;
                while(temp->next!=NULL){
                    temp=temp->next;
                }
                tail = p;
                temp->next = p;
                p->prev = temp;
                cout<<"Node Appended."<<endl;
            }
        }
        return true;
    }
   
    void Prepend(int k,int d){
        Node*n=new Node(k,d);
        if(exist(k)!=NULL){
            cout<<"Node with key ["<<k<<"] already exists."<<endl;
        }
        else{
            head->prev=n;
            n->next = head;
            head=n;
            cout<<"Node Prepended."<<endl;
        }
    }

    void Print(){
        if(head==NULL){
            cout<<"There is no list to be printed."<<endl;
        }
        else{
            Node*temp = head;
            cout<<"Doubly Linked List: "<<endl;
            while(temp!=NULL){
                cout<<"( "<<temp->key<<" , "<<temp->data<<" )-->";
                temp=temp->next;
            }
        }
    }

    void Concatenate(Doubly&L , Doubly&M){
        L.tail->next = M.head;
        L.Print();
    }

};
int main(){
    Doubly L,M;
    int op=0;
    int k,d,z;
    int number;
    cout<<"**** FOR LIST L ****\n";
    cout<<"How many nodes are there in your list: ";
    cin>>number;
    
    for(int i=0;i<number;i++){
        here:
        Node *ptr = new Node();
        cout<<"\nFor Node("<<i+1<<"): \nEnter Key and Data? "; cin>>k>>d;
           ptr->data = d;
           ptr->key = k;
        if(L.Append(k,d)){
            continue;
        }
        else{
            cout<<endl<<"Re-enter: ";
            goto here;
        }
    }

    cout<<"**** FOR LIST M ****\n";
    cout<<"How many nodes are there in your list: ";
    cin>>number;
    
    for(int i=0;i<number;i++){
        here1:
        Node *ptr = new Node();
        cout<<"\nFor Node("<<i+1<<"): \nEnter Key and Data? "; cin>>k>>d;
           ptr->data = d;
           ptr->key = k;
        if(M.Append(k,d)){
            continue;
        }
        else{
            cout<<endl<<"Re-enter: ";
            goto here1;
        }
    }
    
    L.Concatenate(L,M);

}