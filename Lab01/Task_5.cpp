#include <iostream>
using namespace std;
void MinMax(int *arr, int *min, int *max, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (arr[i] < *min)
		{
			*min = arr[i];
		}
		else if (arr[i] > *max)
		{
			*max = arr[i];
		}
	}
}
int main()
{
	int n = 5, i = 0;
	int *array1 = new int[n];
	int *max = new int;
	int *min = new int;
	*max = i;
	for (i; i < n; i++)
	{
		cout << "enter arr[" << i << "]: ";
		cin >> array1[i];
	}
	i = 0;
	i = array1[i];
	*min = i;
	MinMax(array1, min, max, n);
	cout << endl
		 << "MiNimum value is: " << *min << endl;
	cout << "MaXimum value is: " << *max << endl;
}
