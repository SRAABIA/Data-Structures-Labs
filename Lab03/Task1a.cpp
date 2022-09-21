	//printing series 1,3, 6, 10, 15, 21, 28... using recursion
#include<iostream>
using namespace std;
int series(int);	//function prototype
int counter=2;		//global variable

int main(){
	int st;
	cout<<endl;
	series(1);
}

int series(int start){
	if(start<=100){
		cout<<start<<" ";
		return series(start + ( counter++));
	}
	else
	return (0);
}