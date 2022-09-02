#include <iostream>
#include<iomanip>
using namespace std;
int main()
{
    float **arr = new float *[5]; //rows
    string names[5] = {"Ali", "Hiba", "Asma", "Zain", "Faisal"};
    string sub[5] = {"DS", "AI", "DLD", "STAT", "FA"};
    int size[5] = {5, 4, 3, 3, 5}; 
    float *sgpa = new float[5]{0};
    int i, j, k;
    for (i = 0; i < 5; i++)
    {
        arr[i] = new float[size[i]]; //cols
    }
    // for (i = 0; i < 5; i++)
    // {
    //     cout << endl
    //          << "For " << names[i] << " :: " << endl;
    //     for (j = 0; j < size[i]; j++)
    //     {
    //         cout << "Enter GPA of course " << sub[j] << " : ";
    //         cin >> *(*(arr + i) + j);
    //     }
    // }
    
    // cout<<fixed<<setprecision(2);
    arr[0][0] = 3.66;
    arr[0][1] = 3.33;
    arr[0][2] = 4.0;
    arr[0][3] = 3.0;
    arr[0][4] = 2.66;

    arr[1][0] = 3.33;
    arr[1][1] = 3.0;
    arr[1][2] = 3.66;
    arr[1][3] = 3.0;
    
    arr[2][0] = 4.0;
    arr[2][1] = 3.66;
    arr[2][2] = 2.66;

    arr[3][0] = 2.66;
    arr[3][1] = 2.33;
    arr[3][2] = 4.0;

    arr[4][0] = 3.33;
    arr[4][1] = 3.66;
    arr[4][2] = 4.0;
    arr[4][3] = 3.0;
    arr[4][4] = 3.33;
    
    //CALCULATING SGPA
    for(i=0;i<5;i++){
        for (j = 0; j < size[i]; j++)
        {
            sgpa[i] += *(*(arr + i) + j) * 3;
        }
        int k = 3 * size[i];
        sgpa[i]/=k;
    }
    //DISPLAYING TABLE
    cout << endl
         << "\t\t";
    for (i = 0; i < 5; i++)
    {
        cout << sub[i]<< "\t\t" ; //PRINT SUBJECT NAME
    }
    cout << endl;
    for (i = 0; i < 5; i++)
    {
        cout << endl << names[i] << "\t\t";
        for (j = 0; j < size[i]; j++)
        {
            cout<< *(*(arr + i) + j) << "\t\t" ; //PRINT SCORES
        }
    }
    cout<<endl<<endl<<"\t|\tSGPA\t|"<<endl;
    for (i = 0; i < 5; i++)
    {
        cout << endl << names[i];
        cout<<"\t\t"<<sgpa[i];
    }
    //deallocating memory
    for(i=0;i<5;i++){
        delete[] arr[i];
    }
    delete[] arr;
}
