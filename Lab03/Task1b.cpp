	//printing series 1, 2, 4, 7, 11, 16, 22... using recursion
#include<iostream>
using namespace std;
int series(int);	//function prototype
int counter=1;		//global variable

int main(){
	int st;
	cout<<endl;
	series(1);
}

int series(int start){
	if(start<=100){
		cout<<start<<" ";
		return series(start +( counter++));
	}
	else
	return (0);
}