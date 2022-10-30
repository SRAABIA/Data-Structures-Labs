#include<iostream>
using namespace std;
void print(int**arr,int N){
	for(int i = 0;i< N;i++){
		for(int j=0;j<N;j++){
			cout<<"  "<<arr[i][j];
		}cout<<endl;
	}
}
void Sort(int**arr,int N){
	for(int k=0;k<N;k++){
		for(int i = 0; i< N-1 ; i++){
			for(int j=0; j<N-i-1 ; j++){
				if(arr[k][j]>arr[k][j+1]){
					int temp = arr[k][j];
					arr[k][j] = arr[k][j+1];
					arr[k][j+1] = temp;
				}
			}
		}
	}
}
int main(){
	int N;
	cout<<"Enter dimension N: ";
	cin>>N;
	int** arr = new int*[N];
	for (int i =0 ; i<N ; i++){
		arr[i] = new int[N];
	}
	for(int i = 0;i< N;i++){
		for(int j=0;j<N;j++){
			cout<<endl<<"Enter arr["<<i<<"]["<<j<<"]: ";
			cin>>arr[i][j];
		}
	}
	cout<<endl<<"Before Sorting: \n\n";
	print(arr,N);
	cout<<endl<<"After Sorting: \n\n";
	Sort(arr,N);
	print(arr,N);
}