#include<iostream>
using namespace std;

void print(int*arr,int N){
	cout<<endl;
	for(int i = 0;i< N;i++){
			cout<<"  "<<arr[i];
	}
}

void Sort(int*array,int size){
 	for (int i = 0; i < size ; i= i+2){
	 	for (int j = i+2 ; j < size; j= j+2){
			if (array[i] > array[j]) 
			{
				int temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				}
		}
	}
 	for (int i = 1; i < size ; i= i+2){
	 	for (int j = i+2 ; j < size; j= j+2){
			if (array[i] < array[j]) 
			{
				int temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				}

	
		}
	}
}

int main(){
	int N;
	cout<<"Enter dimension N: ";
	cin>>N;
	int* arr = new int[N];
	for(int i = 0;i< N;i++){
			cout<<endl<<"Enter arr["<<i<<"]: ";
			cin>>arr[i];
	}
	cout<<endl<<"Before Sorting: \n\n";
	print(arr,N);
	Sort(arr,N);
	cout<<endl<<"After Sorting: \n\n";
	print(arr,N);
}