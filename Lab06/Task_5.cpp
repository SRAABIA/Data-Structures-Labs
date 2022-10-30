#include<iostream>
using namespace std;
void print(int*arr,int N){
    cout<<endl;
    for(int i=0;i<N;i++){
        cout<<arr[i]<<" ";
    }
}
void Merge(int* arr,int start,int mid, int stop){
    int i = mid-start+1;
    int j = stop-mid;
    int* left = new int[i];
    int* right = new int[j];
    for(int h=0;h<i;h++){
        left[h] = arr[start+h];
    }
    for(int h=0;h<j;h++){
        right[h] = arr[mid+1+h];
    }
    
}
void MergeSort(int*arr, int start, int stop){
    if(stop < start){
     
    int mid = (start+stop)/2;

    MergeSort(arr,start,mid);
    MergeSort(arr,mid+1,stop);
    Merge(arr,start,mid,stop);
    }
}
int main(){
    int size = 10;
    int*arr=new int[size]{12,44,1,66,3,0,7,2,19,1000};
    cout<<size;
	cout<<endl<<"Before Sorting: \n\n";
    print(arr,size);
    MergeSort(arr,0,size-1);
	cout<<endl<<"After Sorting: \n\n";
    print(arr,size);
}