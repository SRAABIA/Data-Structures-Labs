        //nQueen Problem
#include<iostream>
using namespace std;
bool nQueen(int**, int , int );
bool SafeArray(int**,int ,int , int );
int main(){
        int n;
        cout<<"Enter size of Chess Board: ";
        cin>>n;
    int**arr=new int*[n];
    for(int i=0;i<n;i++){
        arr[i] = new int[n]{0}; //declaring memory and initializing array with zeros.
    }
    if(nQueen(arr,0,n)){ 
        cout<<endl;
        for (int i=0;i<n;i++){
            cout<<"\t\t";
                for (int j=0;j<n;j++){
                cout<<arr[i][j]<<" ";
                } 
                cout<<endl;
        }
    }
    cout<<endl;
}
bool nQueen(int**arr, int row, int n){
    if(row>=n){
        return true; // all rows has been checked and have passed the test
    }
    for(int col = 0; col<n; col++){
        if(SafeArray(arr,row,col,n))
        {
            arr[row][col] = 1;

            if(nQueen(arr,row+1,n)){ 
                return true;    
            }
            arr[row][col] = 0;  
            /**
             *  if control reaches here it means
             *  the current position for queen is not suitable
             * increment column to check next position
             */
        }
    }
    return false; 
    /**
     * if control reaches here it means
     * queen did not find any column in the current row to stand
     */
}
bool SafeArray(int**arr,int row,int col, int n){
    // at first we will check in the same row for the given column
    int r = 0;
    int c = 0;
    for( r ; r<row ; r++){
        if(arr[r][col]==1){
            return false;
        }
    }
    r = row;
    c = col;
    // now checking upward left for the position the queen is currently placed
    while(r>= 0 && c>=0){
        if(arr[r][c]==1){
            return false;
        }
        r--;
        c--;
    }
    r = row;
    c = col;
    // now checking upward left for the position the queen is currently placed
    while(r>=0&& c<n){
        if(arr[r][c]==1){
            return false;
        }
        r--;
        c++;
    }
    return true; // this means queen is at a perfect location 
}