#include<iostream>
using namespace std;
void print(int* arr,int N){
    cout<<endl<<" [";
    for(int i = 0 ; i < N ; i++){
        cout<<" "<<arr[i];
    }
    cout<<" ]";
}
void merge(int*arr,int lb,int mid,int ub,int N){
    int nl = mid-lb+1;
    int nr = ub-mid;
    int k = lb;
    int*left = new int[nl];
    int*right=new int[nr];
    for(int i=0;i<nl;i++){
        left[i]=arr[lb+i];
    }
    for(int j=0;j<nr;j++){
        right[j]=arr[mid+1+j];
    }
    int i=0,j=0;
    while(i<nl && j<nr){
        if(left[i]<=right[j]){
            arr[k] = left[i];
            i++;
        }
        else{
            arr[k]=right[j];
            j++;
        }
        k++;
    }
    while(i<nl){
         arr[k] = left[i];
        k++;i++;
        
    }
    while(j<nr){
        arr[k] = right[j];
        k++;j++;
    }

}
void mergesort(int*arr,int lb,int ub,int N){ // merge sort
    int mid;
    if(lb<ub){
         mid = lb+(ub-lb)/2;
        mergesort(arr,lb,mid,N);
        mergesort(arr,mid+1,ub,N);
        merge(arr,lb,mid,ub,N);
    }
}
void interpolation(int*arr,int n, int key){
    int Low = 0, High = n-1;
    bool flag = true;
    //Checking the corner cases
    while(Low <= High && key >= arr[Low] && key <= arr[High])
    {
    
        if(Low == High)
        {
            cout<<"Element found at position: "<<Low<<endl;
        }
        int q = (key - arr[Low])/(arr[High] - arr[Low]);
        int pos = Low + (High - Low) * q;
        if(arr[pos] == key)
        {
            cout<<"Element found at position: "<<pos<<endl;
            flag = false;
        }
        //If the element is greater than the value at that position
        if(arr[pos] < key)
        {
            Low = pos + 1;
        }
        //If the element is lesser than the value at that position
        else
        {
            High = pos - 1;
        }
    }
    //If the element is not found after traversing the whole array
    if(flag == true)
    {
     cout<<"Element not found."<<endl;
    }
}
int main(){
    int x;
    int arr[] = {14,2,77,1,34,66,4,10,5,16,25,41,81,91,6,100,130,121};
    int n = sizeof(arr)/sizeof(arr[0]);
    mergesort(arr,0,n-1,n);
    print(arr,n);
    cout<<endl<<"Enter the element to be searched\n";
    cin>>x;
    interpolation(arr, n, x);

}