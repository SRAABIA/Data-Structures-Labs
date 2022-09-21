#include<iostream>
using namespace std;
bool nQueen(int**,int,int); //function prototype
bool SafeArray(int**,int,int,int);

int main(){
    int n;
    cout<<"Enter the size of Chess Board: "; cin>>n;
    int **arr = new int*[n];
    for(int i=0;i<n;i++){
        arr[i] = new int[n]{0};
    }
    cout<<endl;
    if(nQueen(arr,0,n)){
        for(int i= 0 ;i<n;i++){
            cout<<"\t\t";
            for(int j=0;j<n;j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}

bool nQueen(int** arr, int row, int n){
    if(row>=n){
        return true;    //queen is at perfect place
    }
    for(int col=0; col<n; col++){

        if(SafeArray(arr,row,col,n)){
            arr[row][col] = 1;
                //current queen is in neighbour of any other??
                //so checking all 3 conditions for the next row: below the current row
            if(nQueen(arr,row+1,n)){
                return true;
            }
            arr[row][col] = 0; //queen is at wrong place :: backtrack now
        }
    }
    return false;
}
bool SafeArray(int** arr, int row, int col, int n){
    //first checking all columns for the current row
    int r = 0;
    for(r ; r<n ; r++){
        if(arr[r][col]==1){
            return false; //means the current position has another queen in neighbour
        }
    }
    int c;
    r = row;
    c = col;
    //now checking for diagonal-upward-left positon
    while(r>=0 && c>= 0){
        if(arr[r][c]==1){
            return false; //means the current position has another queen in neighbour
        }
        r--;
        c--;
    }
    //checking for diagonal-upward-right
    r = row;
    c = col;
    while(r>=0 && c < n){
        if(arr[r][c]==1){
            return false; //means the current position has another queen in neighbour
        }
        r--;
        c++;
    }
    return true; //queen has no neighbour queen; 
}