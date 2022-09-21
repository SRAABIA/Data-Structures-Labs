#include<iostream>
using namespace std;
bool SafeArray(int**arr, int x, int y, int n);
bool RatInMaze(int**arr, int x, int y, int n, int**sol);

int main(){
    int n;
    cout<<"Enter n: "; cin>>n;
    int**arr =  new int*[n];
    for(int i = 0;i<n;i++){
        arr[i] = new int[n]{0};
    }
    for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout<<endl<<"Enter arr["<<i<<"]["<<j<<"]: ";
			cin >> arr[i][j];
		}
	}
    cout << endl<<"Array Input: "<<endl;
	for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout <<" "<< arr[i][j] << " ";
			}
			cout << endl;
		}
    //creating another array for solution
	int **solArr = new int *[n];
	for (int i = 0; i < n; i++)
	{
		solArr[i] = new int[n]{0};
	}
	if (RatInMaze(arr, 0, 0, n, solArr))
	{	//prints solution array 
	cout<<endl<<"Final Array from main"<<endl;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cout << solArr[i][j] << " ";
			}
			cout << endl;
		}
	}

}

bool RatInMaze(int**arr, int x, int y, int n, int**sol){
	if(x == (n-1) && y == (n-1) ){ //base case
		sol[x][y] =1; 
		return true;
	}
	if(SafeArray(arr,x,y,n)){
		sol[x][y]=1;
		// for(int i=0;i<n;i++){
		// 	for(int j=0;j<n;j++){
		// 		cout<<sol[i][j]<<" ";
		// 	}
		// 	cout<<endl;
		// }
		// cout<<endl<<"NEXT:"<<endl;
	
	if(RatInMaze(arr,x+1,y,n,sol)){
		return true;
	}
	if(RatInMaze(arr,x,y+1,n,sol)){
		return true;
	}
	sol[x][y]=0;
	return false;//backtrack
	}
	return false;
}

bool SafeArray(int**arr,int x,int y, int n){
	if(x<n && y<n && arr[x][y]==1){
		return true;
	}
	return false;
}