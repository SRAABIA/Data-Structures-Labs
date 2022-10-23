#include<iostream>
using namespace std;
class Node {
    public:
    int key;
    int data;
    Node* next;
    Node(){
        key = 0; 
        data = 0;
        next = NULL;
    }
    Node(int k,int d){
        key = k; 
        data = d;
        next = NULL;
    }
};
class CircularSingly{
    public:
    Node* head;
    CircularSingly(){
        head = NULL;
    }
    Node* exist(int k){
        Node* temp = NULL;
        Node* ptr = head;
        if (ptr == NULL) { //there is nothing to compare with
            temp = ptr;
        } 
        else {
            do{
                if(ptr->key == k){
                    temp = ptr;
                }
                ptr = ptr->next;
            }while(ptr != head);
           
        }
        return temp;
    }

    void Append(int k, int d){
        if(exist(k)==NULL){
            Node*n = new Node(k,d);
            if(head == NULL){
                head = n;
                n->next = head;
                cout<<"Node Appended."<<endl;
            }
            else{
                Node* temp = head;
                while(temp->next != head){
                    temp = temp->next;
                }
                temp->next = n;
                n->next = head;
                cout<<"Node Appended."<<endl;
            }
        }
        else{
            cout<<"Node Already exists with key ["<<k<<"]."<<endl;
        }
    }

    void Prepend(int k,int d){
        if(exist(k) == NULL){
            Node*n = new Node(k,d);
            if(head == NULL){
                head = n;
                n->next = head;
                cout<<"Node Prepended."<<endl;
            }
            else{
                Node* ptr = head;
                while(ptr->next != head){
                    ptr = ptr->next;
                }
                ptr->next = n;
                n->next = head;
                head = n;
                cout<<"Node Prepended."<<endl;
            }
        }
        else{
            cout<<"Node Already exists with key ["<<k<<"]."<<endl;
        }
    }

    void Insert(int key1, int k, int d){
        Node* old = exist (key1);
        Node* n = new Node(k,d);
        if(old!=NULL){
            if((exist(n->key))==NULL){
                if(old->next == head){
                    old->next = n;
                    n->next = head;
                    cout<<"Node Inserted"<<endl;

                }
                else{
                    n->next = old->next;
                    old->next = n;
                    cout<<"Node Inserted"<<endl;
                }
            }
            else{
            cout<<"Node Already exists with key ["<<k<<"]."<<endl;
            }
        }   
        else{
            cout<<"Node does not exist with key ["<<key1<<"]."<<endl;
        }     
    }

    void Delete(int k){
        Node* n = exist(k);
        if(n!=NULL){
           if(head == n){
            Node* temp = head;
            while(temp->next!= head){
                temp=temp->next;
            }
            temp->next = head->next; 
            delete(head);
            head = temp->next;
            cout<<"Node Deleted."<<endl;
           }
        else{
            Node* temp = NULL;
            Node* previous = head;
            Node* current = head->next;
            while(current != NULL){
                if(current->key == k){
                    temp = current;
                    current = NULL;
                }
                else{
                    previous = previous->next;
                    current = current->next;
                }
            }
            previous->next   = temp->next;
            delete(temp);
            cout<<"Node Deleted."<<endl;
        }
        }
    }
 
    void Update(int k, int d){
        Node* n = exist(k);
        n->data = d;
        cout<<"Node Updated."<<endl;

    }
    
    void Print(){
        if (head == NULL){
            cout<<"There is no list to be printed."<<endl;
        }
        else{
            Node* temp = head;
            cout<<"Circular Singly Linked List: "<<endl;
           do{
                cout<<"( "<<temp->key<<" , "<<temp->data<<" )-->";
                temp=temp->next;
            } while(temp != head);
        }
    }
};
int main(){
    CircularSingly obj;
    int option;
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
        case 1:
        cout << "Append Node Operation \nEnter key & data of the Node to be Appended" << endl;
        cin >> key1 >> data1;
        obj.Append(key1,data1);
        break;

        case 2:
        cout << "Prepend Node Operation \nEnter key & data of the Node to be Appended" << endl;
        cin >> key1 >> data1;
        obj.Prepend(key1,data1);
        break;

        case 3:
        cout << "Insert Node After Operation \nEnter key of existing Node after which you want to Insert this New node: " << endl;
        cin >> k1;
        cout << "Enter key & data of the New Node first: " << endl;
        cin >> key1;
        cin >> data1;
        obj.Insert(k1,key1,data1);
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
        case 6:
            obj.Print();
        break;
        case 7:
        system("cls");
        break;

    } 
    
    }while(option!=0);
}