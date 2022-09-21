        //find the sum of digits of a number using recursion.
#include<iostream>
using namespace std;
int log;
int sum(int n){
    if(n>0) {
        log += n%10;
        n/=10;
        return sum(n);
    }
    else return log;
}
int main(){
    int n;
    cout<<"Enter number: ";
    cin>>n;
   cout<<"Sum is: "<< sum(n);
}
