#include<iostream>
using namespace std;
class Node {
    public:
    int key;
    int data;
    Node* next;
    Node* prev;
    Node(){
        key = 0; 
        data = 0;
        next = NULL;
        prev = NULL;
    }
    Node(int k,int d){
        key = k; 
        data = d;
        next = NULL;
        prev = NULL;
    }
};
class CircularDoubly{
    public:
    Node* head;
    Node* tail;
    CircularDoubly(){
        head = NULL;
        tail = NULL;
    }
    
    Node* exist(int k){
        Node* p = head;
        Node* temp = NULL;
        if(p==NULL)
        {
            temp = p;
        }
        else{
            do{
                if(p->key == k){
                    temp = p;
                }
                p = p->next;
            }while(p!=head);
        }
        return temp;
    }
    
    void Append(int k, int d){
        if(exist(k)==NULL){
            Node*n = new Node(k,d);
            Node*temp = head;
            if(head == NULL && tail == NULL){
                head = tail = n;
                head->next = head->prev  = tail;
                tail->next = tail->prev = head;

               cout<<"Node Appended."<<endl;
            }
            else{
                tail->next = n;
                n->prev = tail;
                tail = n;
                head->prev = tail;
                tail->next = head;
                cout<<"Node Appended."<<endl;
            }
        }
        else{
            cout<<"Node Already exists with key ["<<k<<"].";
        }
    }

    void Prepend(int k,int d){
        if(exist(k)==NULL){
            Node*n = new Node(k,d);
            if(head == NULL && tail == NULL){
                head = tail = n;
                head->prev = tail->prev = tail;
                head->next = tail->next = head;
                cout<<"Node Prepended."<<endl;
            }
            else{
                n->next = head;
                head->prev = n;
                n->prev = tail;
                head = n;
                tail->next = head;
                cout<<"Node Prepended."<<endl;
            }
        }
        else{
            cout<<"Node Already exists with key ["<<k<<"]."<<endl;
        }
    }

    void Insert(int key1, int k, int d){
        Node* old = exist(key1);
        Node* n = new Node(k,d);
        if(old != NULL){
            if(exist ( n->key ) == NULL){
                if(key1 == tail->key){ //last node
                    n->next = old->next;
                    tail->next = n;
                    n->prev = tail;
                    tail = n;
                    head->prev = n;
                    cout<<"Node Inserted"<<endl;
                }
                else{
                    n->next = old->next;
                    old->next = n;
                    n->prev = old;
                    n->next->prev = n;
                    cout<<"Node Inserted"<<endl;
                }
            }
            else{
            cout<<"Node Already exists with key ["<<k<<"]."<<endl;
            }
        }
        else{
            cout<<"No Node found with key ["<<key1<<"]."<<endl;
        }
    }

    void Delete(int k){
        Node* n = exist(k);
        if(n != NULL){
            if(head == n){
                tail->next = head->next;
                (head->next)->prev = tail;
                head = head->next;
                delete (n);
                cout<<"Node Deleted."<<endl;
            }
            else{
                n->prev->next = n->next;
                n->next->prev = n->prev;
                delete (n);
                cout<<"Node Deleted."<<endl;
            }
        }
        else{
            cout<<"Node Already exists with key ["<<k<<"]."<<endl;
        }

    }
    void Update(int k, int d){
        Node* n = exist(k);
        if(n != NULL){
            n->data = d;
            cout<<"Node Updated."<<endl;
        }
        else{
            cout<<"No Node exists with key ["<<k<<"]."<<endl;
        }
    }

    void Print(){
        if(head == NULL){
            cout<<"There is no list."<<endl;
        }
        else{
            Node*temp = head;
             cout<<"Circular Doubly Linked List: "<<endl;
           do{
                cout<<"<-->( "<<temp->key<<" , "<<temp->data<<" )<-->";
                temp=temp->next;
            } while(temp != head);
        }
    }
    
    void Print_rev(){
        if(head == NULL){
            cout<<"There is no list."<<endl;
        }
        else{
            Node*temp = tail;
             cout<<"Circular Doubly Linked List: "<<endl;
           do{
                cout<<"( "<<temp->key<<" , "<<temp->data<<" )-->";
                temp=temp->prev;
            } while(temp != head);
        }
    }
};
int main(){
    CircularDoubly obj;
        int option = 0;
    int key1, k1, data1;
    do{
        cout <<endl<< "What operation do you want to perform? --Enter 0 to exit." << endl;
        cout << "1. Append()" << endl;
        cout << "2. Prepend()" << endl;
        cout << "3. Insert()" << endl;
        cout << "4. Delete()" << endl;
        cout << "5. Update()" << endl;
        cout << "6. Print()" << endl;
        cout << "7. Clear Screen" << endl <<":: ";

        cin >> option;
        Node * n1 = new Node();
        switch(option){
        case 1:{
        cout << "Append Node Operation \nEnter key & data of the Node to be Appended" << endl;
        cin >> key1 >> data1;
        obj.Append(key1,data1);
        }
        break;

        case 2:{
        cout << "Prepend Node Operation \nEnter key & data of the Node to be Appended" << endl;
        cin >> key1 >> data1;
        obj.Prepend(key1,data1);}
        break;

        case 3:{
        cout << "Insert Node After Operation \nEnter key of existing Node after which you want to Insert this New node: " << endl;
        cin >> k1;
        cout << "Enter key & data of the New Node first: " << endl;
        cin >> key1;
        cin >> data1;
        obj.Insert(k1,key1,data1);}
        break;
        
        case 4:
            cout << "Delete Node By Key Operation - \nEnter key of the Node to be deleted: " << endl;
            cin >> k1;
            obj.Delete(k1);
        break;

        case 5:
        cout<<"Update Node By Key Operation - \nEnter key of the Node to be updated: " << endl;
        cin>>k1;
        if(obj.exist(k1)!= NULL){
            cout<<"Enter the new data for key ["<<k1<<"] :";
            cin>>data1;
            obj.Update(k1,data1);
        }
        else{
            cout<<"No node with key ["<<k1<<"] exists!"<<endl;
        }
        break;
        case 6:{
            obj.Print();
			}
            
        break;
        case 7:
        system("cls");
        break;
    } 
    
    }while(option!=0);
}