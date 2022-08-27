#include <iostream>
using namespace std;
int factor(int n)
{
	int i, sum = 0;
	if (n == -1)
		return 0;
	else
	{
		for (i = 1; i <= n; i++)
		{
			if (n % i == 0)
			{
				cout << i << " ";
				sum += i;
			}
		}
		return sum;
	}
	return 0;
};
int main()
{
	int n;
	cout << "Enter a num: ";
	cin >> n;

	cout << endl
		 << "Sum is: " << factor(n);
	return 0;
}
