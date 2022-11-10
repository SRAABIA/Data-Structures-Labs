#include<iostream>
using namespace std;
class Node{
    public:
    int key;
    Node* next;
    Node(){
        key=0;
        next = NULL;
    }
};
int number;
class Queue{
    public:
    Node*front;
    Node*rear;
    int count;
    Queue(){
        front =NULL;
        rear=NULL;
        count = 0;
    }
    bool isexist(Node* n){
        Node* temp = front;
       while(temp!=NULL){
        if(temp->key == n->key){
            return true;
        }
        temp = temp->next;
       }
       return false;

    }
    bool isempty(){
        if(front==NULL && rear==NULL){
            return true;
        }
        return false;
    }
    bool QueueCapacity( ){
        if(count == number){
            return true;
        }
        return false;
    }
    void ADDMember(Node* n){
        if(isempty()){
            front = n;
            rear = n;
            count++;
            cout<<endl<<"Node added to queue.";
        }
        else if(QueueCapacity()){
            cout<<endl<<"Stack overflow";
        }
        else if(isexist(n)){
            cout<<endl<<"Node already exists in Queue.";
        }
        else{
           count++;
           rear->next=n;
           rear = n;
           cout<<endl<<"Node added to queue.";
        }
    }

    Node* RemoveMember(){
        if(isempty()){
            cout<<endl<<"The Queue is Empty.";
            return NULL;
        }
        else {
            Node* temp = NULL;
            if(front == rear){
                temp = front;
                front = NULL;
                rear = NULL;
                count--;
                return temp;
            }
            else{
                temp = front;
                count--;
                front = front->next;
                return temp;
            }
        }
    }
    
    void display() 
    {
        if(isempty())
        {
        cout << "Queue is Empty" << endl;
        }
        else
        {
        cout << "All values in the Queue are :" << endl<<endl;
        Node *temp=front;
        while(temp!=NULL)
        {
            cout<<"("<<temp->key<<")"<<" -> ";
            temp=temp->next;
        }
        cout<<endl;
        }
    }

};
int main(){
    Queue q;
  int opt,key, x;
    cout<<endl<<"How many nodes are there in your Queue: ";
    cin>>x;
    number = x;
    do{
    cout << endl<<endl<<"What operation do you want to perform?"
	 <<"Select Option number. Enter 0 to exit." << endl;
    cout << "1. ADDMember()" << endl;
    cout << "2. RemoveMember()" << endl;
    cout << "3. isempty()" << endl;
    cout << "4. QueueCapacity()" << endl;
    cout << "5. display()" << endl;
    cout << "6. Clear Screen" << endl << endl;
 	 cin >> opt;
     Node* n = new Node();
     switch(opt){
        case 1:
        cout<<endl<<"Enter key for node you want to enter: "; 
        cin>>key;
        n->key = key;
        q.ADDMember(n);
        break;
        case 2:
        n = q.RemoveMember();
        if(n!=NULL){
        cout<<endl<<"Node with value : ["<<n->key<<"] is popped out of queue.";
        delete n;
        }

        break;
        case 3:
        if(q.isempty()){
            cout<<endl<<"Queue is empty";
        }
        else{
            cout<<endl<<"Queue is not empty";
        }
        break;
        case 4:
        if(q.QueueCapacity()){
            cout<<endl<<"Queue is full";
        }
        else{
            cout<<endl<<"Queue is not full";
        }
        break;
        case 5:
        q.display();
        break;
        case 6:
        system("cls");
        break;
        default:
        cout<<endl<<"Choose wisely!";
     }
 	 
    }while(opt!=0);
    return 0;
}