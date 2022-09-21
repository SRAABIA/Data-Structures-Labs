        //sorting array using recursion
#include<iostream>
using namespace std;
void nontail(int*,int); //function prototype

int main(){
    int arr[5]={5,4,3,2,1};     //Hardcoding values
    for(int i=0;i<5;i++){     //Taking Input 
        cout<<"Enter arr["<<i<<"]: ";
        cin>>arr[i];
    }
    cout<<"Unsorted Array:-"<<endl;
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
    nontail(arr, 5);          // function call   
                             //passing array's base address and length
    cout<<endl<<"Sorted Array:-"<<endl;
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
}

void nontail(int* arr,int len){     //function definition
                                    //pointer to array
    if(len==1)
    return;
    
    nontail(arr,len-1); 
    int last = len-1;
    for(int i = last;i>0;i--){ 
        if(arr[i]<arr[i-1]){    //Sorting
            int temp = arr[i];
            arr[i] = arr[i-1];
            arr[i-1] = temp;
        }
    }
}