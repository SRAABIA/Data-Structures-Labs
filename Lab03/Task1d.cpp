        // count the digits of a given number using recursion
#include<iostream>
using namespace std;
int log;
int count(int n){
    if(n>0){
        n/=10;
        log++;
        return count(n);
    }
    else
    return log;
}
int main(){
    int n;
    cout<<"Enter number: ";
    cin>>n;
    cout<<"No. Of digits: "<<count(n);
}