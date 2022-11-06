#include<iostream> 	//Radix Sort
#include<time.h>
using namespace std;
void print(int *arr,int N){
    cout<<endl<<" [";
    for(int i=0;i<N;i++){
        cout<<"  "<<arr[i];
    }
    cout<<" ]"; 
}
int FindMax(int *arr, int N){
    int max = arr[0];
    for(int y=1;y<N;y++){
        if(arr[y]>max){
            max = arr[y];
        }
    }
    return max;
}
void CountingSort(int *arr, int N, int div){
    int* output = new int[N];
    //number of unique elements
    int count[10] = {0}; 
    for(int i = 0; i<N; i++){
    	count[(arr[i]/div)%10]++;
	}
	//cumulative count
	for(int i=1; i<10; i++){ 	
		count[i]= count[i] + count[i-1];
	}
	// two same values at certain unit place should not change positions.
	// Therefore, looping in reverse.
	for(int i = N-1; i>=0; i--){
		output[count[(arr[i]/div)%10]-1] = arr[i];
		count[(arr[i]/div)%10]--;
	}
	// maintaining array
	for(int i=0;i<N;i++){
		arr[i] = output[i];
	}
}
void RadixSort(int *arr, int N){
    int max = FindMax(arr,N);
    for(int div = 1;(max/div)>0 ; div*=10){
        CountingSort(arr,N,div);
    }
}
int main(){
    int*arr= new int[15];
    srand(time(0));
    for(int i=0;i<15;i++){
    arr[i] = (rand() % (20 - 1 + 1)) + 1;
    }
    cout<<endl<<"Before Sorting: ";
    print(arr,15);
    cout<<endl<<endl;
    cout<<endl<<"After Sorting: ";
    RadixSort(arr,15);
    print(arr,15);
    return 0;
}