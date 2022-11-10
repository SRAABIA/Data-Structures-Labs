#include<iostream>
using namespace std;
class Queue{
    public:
    int front;
    int rear;
    int arr[5];
    Queue(){
        this->rear = -1;
        this->front = -1;
        for(int i=0;i<5;i++){
            this->arr[i] = 0;
        }
    }
    bool isempty(){
        if(front==-1&&rear==-1){
            return true;
        }
        else return false;
    }
    bool QueueCapacity(){
        if(rear==4){
            return true;
        }
        else return false;
    }
    void ADDMember(int val){
        if(QueueCapacity()){
            cout<<"Queue full";
            return;
        }
        else if(isempty()){
            rear=0;
            front=0;
            arr[rear]=val;
        }
        else{
            rear++;
            arr[rear]=val;
        }
    }
    int RemoveMember(){
        int x=0;
        if(isempty()){
        cout<<"Queue is empty.";
        }
        else if(rear==front){ //for a single element
            x = arr[rear];
            rear = -1;
            front = -1;
        }
        else{
            cout<<"front val: "<<front<<endl;
            x = arr[front];
            arr[front] = 0;
            front++;
        }
        return x;
    }
  void display() {
    cout << "All values in the Queue are - " << endl;
    for (int i = 0; i < 5; i++) {
      cout << arr[i] << "  ";
    }
  }
};
int main() {
  Queue q1;
  int value, option;

  do {
    cout << "\n\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
    cout << "1. ADDMember()" << endl;
    cout << "2. RemoveMember()" << endl;
    cout << "3. isempty()" << endl;
    cout << "4. QueueCapacity()" << endl;
    cout << "5. display()" << endl;
    cout << "6. Clear Screen" << endl << endl;

    cin >> option;

    switch (option) {
    case 0:
      break;
    case 1:
      cout << endl<< "ADDMember Operation \nEnter an item to ADDMember in the Queue" << endl;
      cin >> value;
      q1.ADDMember(value);
      break;
    case 2:
      cout << endl<<"RemoveMember Operation \nRemoveMember Value : " << q1.RemoveMember() << endl;
      break;
    case 3:
      if (q1.isempty())
        cout <<  endl<<"Queue is Empty" << endl;
      else
        cout <<  endl<<"Queue is not Empty" << endl;
      break;
    case 4:
      if (q1.QueueCapacity())
        cout << endl<< "Queue is Full" << endl;
      else
        cout <<  endl<<"Queue is not Full" << endl;
      break;
    case 5:
      cout <<  endl<<"Display Function Called - " << endl;
      q1.display();
      break;
    case 6:
      system("cls");
      break;
    default:
      cout <<  endl<<"Enter Proper Option number " << endl;
    }

  } while (option != 0);

  return 0;
}
