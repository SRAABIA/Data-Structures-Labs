	//printing series 1,3, 6, 10, 15, 21, 28... using INDIRECT recursion
#include<iostream>
using namespace std;
int series(int);	//function prototype
int indirect(int);	//function prototype
int counter=2;		//global variable

int main(){
	int st;
	cout<<endl;
	series(1);		//function call
}

int series(int start){		//function definition
	if(start<=100){
		cout<<start<<" ";
		return indirect(start+(counter++));
	}
	else return 0;
}
int indirect(int start){
    if(start<=100){
		cout<<start<<" ";
		return series(start + ( counter++));
	}
	else return 0;
}
