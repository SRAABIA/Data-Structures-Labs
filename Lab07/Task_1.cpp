#include<iostream>
using namespace std;
void print(int* arr,int N){
    cout<<endl<<" [";
    for(int i = 0 ; i < N ; i++){
        cout<<" "<<arr[i];
    }
    cout<<"] ";
}
void majority(int* arr, int N)
{
    int max=0, maxe=-1;
    for(int i=0;i<N;i++){
        int count = 0;
        for(int j=0;j<N;j++){
            if(arr[i] == arr[j]){
                count++;
            }
        }
        if(count > max ){
            max = count;
            maxe = i;
        }
    }
    if(max > N/2){
        cout<<endl<<arr[maxe]<<" appears most.";
    }
    else{
        print(arr,N); cout<<" has no majority elements.";
    }

}
int main(){
   int N;
   cout<<"Enter size of array N = ";
   cin>>N;
   int*arr = new int[N];
   for(int i  = 0 ; i < N; i++){
    cout<<endl<<"Enter arr["<<i+1<<"] : ";
    cin>>arr[i];
   }
   majority(arr,N);
   return 0;
}

