#include<iostream>
using namespace std;
int main(){
	int *arr = new int[10]{0};
	int i=0,j=0;
	for(i;i<10;i++){
		cout<<endl<<"Enter arr["<<i<<"]: ";
		cin>>arr[i];
	}
	cout<<endl<<"\tASCENDING ORDER"<<endl<<endl<<"\t";
	for(i=0;i<10;i++){
		for(j=0;j<10;j++){
			if(arr[j]>arr[i]){
				int temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
		}
	}
	for(i=0;i<10;i++){
		cout<<" "<<arr[i];
	}
	cout<<endl<<endl<<"\tDESCENDING ORDER"<<endl<<endl<<"\t";
	for(i=0;i<10;i++){
		for(j=0;j<10;j++){
			if(arr[j]<arr[i]){
				int temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
		}
	}
	for(i=0;i<10;i++){
		cout<<" "<<arr[i];
	}
}