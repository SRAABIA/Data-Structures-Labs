#include <iostream>
using namespace std;
void print(string *arr, int N)
{
    cout << endl;
    for (int i = 0; i < N; i++)
    {
        cout << "  " << arr[i];
    }
}

void Sort(string *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < array[i].length(); j++)
        {
            array[i][j] = tolower(array[i][j]);
        }
    }

    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                string temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int N;
    cout << "Enter dimension N: ";
    cin >> N;
    string *arr = new string[N];
    for (int i = 0; i < N; i++)
    {
        cout << endl
             << "Enter arr[" << i << "]: ";
        cin >> arr[i];
    }
    cout << endl
         << "Before Sorting: \n\n";
    print(arr, N);
    Sort(arr, N);
    cout << endl
         << "After Sorting: \n\n";
    print(arr, N);
}