#include<iostream>
using namespace std;
void print(int*arr,int N){
	for(int i = 0;i< N;i++){
			cout<<"  "<<arr[i];
	}
}

void Sort(int*arr,int N){
	int count = 0 ,j,temp;
	for(int i = 1 ; i < N ; i++){
		temp = arr[i];
		j = i-1;
		while(arr[j]>temp && j>=0 ){
			arr[j+1] = arr[j];
			j--;
			count++;
		}	
		arr[j+1] = temp;
	}
	cout<<endl<<"Count is: "<<count<<endl;
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