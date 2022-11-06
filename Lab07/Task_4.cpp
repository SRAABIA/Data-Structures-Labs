#include<iostream>      //implementation of Quick Sort
#include<time.h>
using namespace std;
void print(int*arr, int N){
    cout<<endl<<" [";
    for(int i=0;i<N;i++){
        cout<<" "<<arr[i];
    }
    cout<<" ]";    
}
int swap(int&a,int&b){
    int temp = a;
    a = b;
    b = temp;
}
int Partition(int *arr, int lb,int ub){
    int pivot = arr[lb];
    int start = lb;
    int end = ub;
    while(start <= end){
        while(arr[start] <= pivot){
            start++;
        }
        while(arr[end]>pivot){
            end--;
        }
        if(start<=end){
            swap(arr[start],arr[end]);
        }
    }
    swap(arr[lb], arr[end]);
    // print(arr,26);
    return end;
}
void QuickSort(int *arr, int lb,int ub){
    if(lb<ub){
        int loc = Partition(arr,lb,ub);
        QuickSort(arr,lb,loc-1);
        QuickSort(arr,loc+1,ub);
    }
    return;
}
int main(){
	//26 cards
    int*arr= new int[26];
    srand(time(0));
    for(int i=0;i<26;i++){
    arr[i] = (rand() % (13 - 1 + 1)) + 1;
    }
    cout<<endl<<"Before Sorting: ";
    print(arr,26);
    cout<<endl<<"After Sorting: ";
    QuickSort(arr,0,25);
    print(arr,26);
}