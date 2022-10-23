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
    Doubly(){
        head = NULL;
    }
    Doubly(Node*n){
        head = n;
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

    void Append(int k,int d){
        if(exist(k) != NULL){
            cout<<"Node with key ["<<k<<"] already exists."<<endl;
        }
        else{
            Node* p = new Node(k,d);
            if(head==NULL){
                head = p;
                cout<<"Node Appended."<<endl;
            }
            else{
                Node*temp=head;
                while(temp->next!=NULL){
                    temp=temp->next;
                }
                temp->next = p;
                p->prev = temp;
                cout<<"Node Appended."<<endl;
            }
        }
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

    void Insert(int key, int k,int d){
        Node* ptr = new Node(k,d);
        Node* given = exist(key);
        if(given == NULL){
            cout<<"No node exists with key: "<<key<<endl;
        }
        else{
            if(exist(k)!=NULL){
            cout<<"Node with key ["<<k<<"] already exists."<<endl;
            }
            else{
                Node*temp = given->next;
                if(temp == NULL){
                    given->next = ptr;
                    ptr->prev = given;
                }
                else{
                    given->next = ptr;
                    ptr->prev = given;
                    ptr->next = temp;
                }
               
            }
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
                cout<<"( "<<temp->key<<" , "<<temp->data<<" )<-->";
                temp=temp->next;
            }
        }
    }

    void Delete(int k){
        Node* n = exist(k);
        Node*ptr = (n->prev);

        if(n!=NULL){
            // while(temp!=NULL){
            //     if(temp->key == k){
            //         temp->prev = temp->next;
            //         temp->next->prev = temp->prev;
            //         delete(temp);
            //     }
            //     temp=temp->next;
            // }
            if(head->key == k){
                head = head->next;
                delete(n); 
                cout<<"Deletion Successful!"<<endl;
            }
            else if(n->next == NULL){
                (n->prev)->next = NULL;
                delete(n); 
                cout<<"Deletion Successful!"<<endl;
            }
            else{
                (n->prev)->next = n->next;
                (n->next)->prev = n->prev;
                delete(n); 
                cout<<"Deletion Successful!"<<endl;
            }

        }
        else{
            cout<<"Key ["<<k<<"] not found."<<endl;
        }
    }

    void Update(int k,int d){
        Node* n = exist(k);
        n->data = d;
        cout << "Node Data Updated Successfully" << endl;
    }

};
int main(){
    Doubly obj;
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