#include <iostream>
using namespace std;
int main()
{
    bool **arr = new bool *[5]; //rows
    for (int i = 0; i < 5; i++)
    {
        arr[i] = new bool[5]{false}; //col
    }

    arr[0][1] = true;
    arr[0][3] = true;
    arr[0][4] = true;

    arr[1][0] = true;
    arr[1][2] = true;
    arr[1][4] = true;

    arr[2][1] = true;

    arr[3][0] = true;
    arr[3][4] = true;

    arr[4][0] = true;
    arr[4][1] = true;
    arr[4][3] = true;
	
        cout<<endl;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            cout<<"\t"<<arr[i][j];
		}
		cout<<endl;
    }
    int p1,p2;
    cout<<endl<<"Enter Friend No.(1-5) You want to confirm Friendship with?"<<endl<<":: ";
    cin>>p1>>p2;
    if(arr[p1-1][p2-1]){
            cout<<endl<<"The "<<p1<<" & "<<p2<<" are mutual friends";
            exit(0);
    }
    cout<<endl<<"The "<<p1<<" & "<<p2<<" are NOT mutual friends";
}
