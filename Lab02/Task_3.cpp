#include<iostream>
using namespace std;
int main(){
	int i=0,j=0,k=0,b=0;
	int *arr= new int[10]{0};
	int *aux_arr=new int[10]{0};
	for(i = 0; i<10;i++){
		cout<<endl<<"Enter arr["<<i<<"]: ";
		cin>>arr[i];
	}
	for(i=0;i<10;i++){
		for(j=0;j<10;j++){
			if(arr[j]>arr[i]){
				int temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
		}
	}
	//array is now sorted
	cout<<endl<<"Sorted Array: "<<endl;
	for(i=0;i<10;i++){
		cout<<" "<<arr[i];
	}
	cout<<endl<<"New Array: "<<endl;
	for(i=0,j=9;i<10,j>=0;i++,j--){
		aux_arr[b] = arr[j];
		aux_arr[b+1] = arr[i];
		b+=2;	
	}
		
	for(i=0;i<10;i++){
		cout<<" "<<aux_arr[i];
	}
}
  