        //Calculate the sum of numbers from 1 to n using recursion
#include<iostream>
using namespace std;
int log;
int sum(int n,int i){
    if(i<=n){
        log += i;
        i++;
        sum(n,i);
    }
    else return log;
}
int main(){
    int n;
    cout<<"Enter number: ";
    cin>>n;
    cout<<"Sum is: "<<sum(n,1);
}