		//Print Fibonacci Series using recursion.
#include<iostream>
using namespace std;
int fin(int n){
	if(n==0||n==1){	//base case
		return n;
	}
	else{
		return (fin(n-1)+fin(n-2));
	}
}
int main(){
	int n;
	cout<<"Enter num: ";
	cin>>n;
	cout<<"\nFibobonaci Of : "<<n<<endl;
	for(int i=0;i<n;i++)
		cout<<fin(i)<<" ";
}