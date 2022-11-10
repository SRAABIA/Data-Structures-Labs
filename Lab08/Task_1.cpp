#include<iostream>
#include<stack>
using namespace std;
class Stack{
    public:
    int top;
    int arr[10];
    Stack(){
        top = -1;
        for(int i=0;i<10;i++){
            arr[i] = 0;
        }
    }
    bool isEmpty(){
        if(top==-1){
            return true;
        }
        return false;
    }
    bool isFull(){
        if(top==9) return true;
        else return false;
    }
    void push(int k){
        if(isFull()){
            cout<<endl<<endl<<"Stack overflow";
        }
        else{
            top++;
            arr[top] = k;
        }
    }
    int pop(){
        if(isEmpty()){
            cout<<endl<<endl<<"Stack underflow";
            return 0;
        }
        else{
            int x = arr[top];
            arr[top]=0;
            top--;
            return x;
        }
    }
    void display(){
        cout<<endl<<"[ ";
        for(int i = 9 ; i>=0;i--){
           cout<<arr[i]<<"  ";
        }
        cout<<" ]";
    }

};
int main(){
    cout<<"STACK IMPLEMENTATION";
    cout<<endl;
    Stack s;
    int k = 0;
    for(int i=0;i<=10;i++){
        cout<<endl<<"Enter arr["<<i<<"]: ";
        cin>>k;
        s.push(k);
    }
    cout<<endl;
    for(int i = 9 ; i>=-1 ; i--){
        if(i<0){
            s.pop();
        }
        else{
            cout<<endl<<i<<". Pop value: "<<" "<<s.pop();
        }
    }

}