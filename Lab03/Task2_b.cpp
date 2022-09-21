	//printing series 1, 2, 4, 7, 11, 16, 22... using INDIRECT recursion
#include<iostream>
using namespace std;
int series(int);
int indirect (int);
int counter=1;

int main(){
	int st;
	cout<<endl;
	series(1);
}

int series(int start){
	if(start<=100){
		cout<<start<<" ";
		return indirect(start +( counter++));
	}
	else
	return (0);
}

int indirect(int start){
	if(start<=100){
		cout<<start<<" ";
		return series(start +( counter++));
	}
	else
	return (0);
}