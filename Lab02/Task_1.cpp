#include<iostream>
using namespace std;
int main(){
	int r,c,flag=0;
	int i=0,j=0;
	
	cout<<endl<<"Enter number of rows: ";
	cin>>r;
	cout<<endl<<"Enter number of columns: ";
	cin>>c;
	int arr[r][c] = {0};
	for(i=0 ; i<r;i++){
		for(j=0;j<c;j++){
			cout<<"arr["<<i<<"]["<<j<<"] : ";
			cin>>arr[i][j];	
		}
	}
		cout<<endl;
	for(i=0 ; i<r;i++){
		for(j=0;j<c;j++){
			cout<<" "<<arr[i][j];	
		}
		cout<<endl;
	}
	for(i=0 ; i<r;i++){
		for(j=0; j<c;j++){
			if(i==j){
				if(arr[i][j] == 1)
				continue;
				else
				cout<<endl<<"Not Identity";
				return 0;
			}
			else{
				if(arr[i][j] !=0){
					cout<<endl<<"Not Identity";
				return 0;
				}
				else
				continue;
			}
		}
	}
	cout<<endl<<"IDENTITY MATRIX";
}