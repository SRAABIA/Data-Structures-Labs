#include <iostream>
#include <time.h>
using namespace std;
void seq_sea(int*arr,int N,int x){
    int count=0;
    for(int i=0;i<N;i++){
        count++;
        if(arr[i]==x){
            cout<<endl<<"Element is found at index: "<<i;
            cout<<endl<<"Number of comparisons: "<<count;
            return;
        }
    }
    cout<<endl<<"Element Not found.";
    return;
}
int main()
{
    int *arr = new int[10];
    int x;
    int a = 47;
    int b = 5923;
    int m = 2743;
    srand(time(0));
    int s = 0;
    while (s < 10)
    {
        int i = (rand() % (999 - 0 + 1)) + 0;
        arr[s] = (a * m + i * b) % 100000;
        cout << endl
             << "arr[" << s << "]: " << arr[s];
        s++;
    }
    cout<<endl<<"Enter an element to search for: ";
    cin>>x;
    seq_sea(arr,10,x);
}