#include<iostream>
using namespace std;
class Node
{
public:
  int key;
  int data;
  Node *next;

  Node()
  {
    key = 0;
    data = 0;
    next = NULL;
  }
  Node(int k, int d)
  {
    key = k;
    data = d;
    next = NULL;
  }
};

class Stack
{
public:
  Node *top;
  int count;
  Stack()
  {
    count = -1;
    top = NULL;
  }

  bool isEmpty()
  {
    if (top == NULL)
    {
      return true;
    }
    else
    {
      return false;
    }
  }

  bool isfull(){
    if(count == 9){
      return true;
    }
    else return false;
  }

  bool IsExist(Node *n)
  {
    Node *temp = top;
    bool exist = false;
    while (temp != NULL)
    {
      if (temp -> key == n -> key)
      {
        exist = true;
        break;
      }
      temp = temp -> next;
    }
    return exist;
  }

 void push(Node*n){
  if(isfull()){
    cout<<endl<<"Stack Overflow : Only 10 values allowed.";
  }
  else{
    if(IsExist(n)){
      cout<<endl<<"This node already exists.";
    }
    
    else if(top == NULL){
      top = n;
      count++;
      cout<<endl<<"Node pushed.";
    }
    else{
      n->next = top;
      top = n;
      count++;
      cout<<endl<<"Node pushed.";
    }
  }
 }

  Node* pop(){
    if(isEmpty()){
      cout<<endl<<"Stack underflow";
      return NULL;
    }
    else{
      Node*temp = top;
      top = top->next;
      count--;
      return temp;
    }
  }

  void display()
  {
    char c = 24;
    cout << "All values in the Stack are :" << endl<<endl;
    Node *temp = top;
    while (temp != NULL)
    {
      cout << "\t(" << temp -> key << "," << temp -> data << ") " << c << endl;
      temp = temp -> next;
    }
    cout << endl;
  }

  void reverse(){
    Node*current = top;
    Node*prev = NULL;
    Node*next1 = current->next;
    while(current!=NULL){
      next1 = current->next;
      current->next = prev;
      prev = current;
      current = next1;
    }
    top = prev;
  }
  void reverse_display(){
  reverse();
     char c = 25;
   Node*temp = top;
    while (temp != NULL)
    {
      cout << "\t(" << temp -> key << "," << temp -> data << ") " << c << endl;
      temp = temp -> next;
    }
    cout << endl;
  reverse();
  }
};
int main(){
   Stack s1;
  int option, key, data;
  do
  {
    cout <<endl<<endl<< "What operation do you want to perform?"
         << "Select Option number. Enter 0 to exit." << endl;
    cout << "1. Push()" << endl;
    cout << "2. Pop()" << endl;
    cout << "3. isEmpty()" << endl;
    cout << "4. display()" << endl;
    cout << "5. reverse_display()" << endl;
    cout << "6. Clear Screen" << endl
         << endl;
    cin >> option;

    Node *node = new Node();

    switch (option)
    {
    case 0:
      break;
    case 1:
      cout << "Enter KEY and VALUE of NODE to push in the stack" << endl;
      cin >> key;
      cin >> data;
      node -> key = key;
      node -> data = data;
      s1.push(node);
      break;
    case 2:
      cout << "Pop Function Called - Poped Value: " << endl;
      node = s1.pop();
      if(node!=NULL){
      cout << "TOP of Stack is: (" << node -> key << "," << node -> data << ")";
      delete node;
      cout << endl;}
      break;
    case 3:
      if (s1.isEmpty())
        cout << "Stack is Empty" << endl;
      else
        cout << "Stack is not Empty" << endl;
      break;
    case 4:
      cout << "Display Function Called - " << endl;
      s1.display();
      cout << endl;
      break;
    case 5:
      cout << "Reverse Display Function Called - " << endl;
      s1.reverse_display();
      cout << endl;
    break;
    case 6:
      system("cls");
      break;
    default:
      cout << "Enter Proper Option number " << endl;
    }

  } while (option != 0);

  return 0;

}