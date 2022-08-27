#include <iostream>
using namespace std;
int main()
{
	int n, i, sum = 0;
	cout << "Enter a num: ";
	cin >> n;
	if (n >= 0)
	{
		for (i = 1; i <= n; i++)
		{
			if (n % i == 0)
			{
				cout << i << " ";
				sum += i;
			}
		}
	}
	else if (n == -1)
		return 0;
	cout << endl
		 << "Sum is: " << sum;
}
