#include<iostream>
using namespace std;
void print(int* arr,int N){
    cout<<endl<<" [";
    for(int i = 0 ; i < N ; i++){
        cout<<" "<<arr[i];
    }
    cout<<"] ";
}
int BinarySearch(int*arr, int N, int target){
     int l = 0;
    int r = N-1;
    
    while(r>=l){
    	int mid = l+(r-l)/2;
        if(target == arr[mid]) return mid;
        else if(target<arr[mid])  r = mid-1;
        else  l = mid+1;
    }
    return -1;
}
int BinarySearch_2(int*arr, int N, int target){
     int l = 0;
    int r = N-1;
    int ans= -1;
    while(r>=l){
    	int mid = l+(r-l)/2;
        if(target == arr[mid]) {ans = mid; l = mid+1;}
        /*  The only difference is after finding the first element,
        the search continues to the right side of the array,
        rather than the left*/
        else if(target<arr[mid])  r = mid-1;
        else  l = mid+1;
    }
    return ans;
}
int main(void){
   int N=10,x;
   int*arr = new int[N]{2,5,5,5,6,6,8,9,9,9};
    print(arr,N);
    cout<<endl<<"Enter target: ";
    cin>>x;
  cout<<endl<<"The 1st occurence @ : "<< BinarySearch(arr,N, x);
  cout<<endl<<"The last occurence @ : "<< BinarySearch_2(arr,N, x);
//   count = right - left + 1
   return 0;
}