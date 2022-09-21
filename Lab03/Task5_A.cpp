#include <iostream>
using namespace std;

bool SafeArr(int row, int col, int n)
{
    if (row >= 0 && col >= 0)
    {
        if (row < n && col < n)
        {
            return true;
        }
        return false;
    }
    return false;
}
bool Count_Paths(int **sol, int r, int c, int n)
{
    if (r == n)
    {
        return true;
    }
    if (c == n)
    {
        if (r < n)
        {
            r++;
            c = 1;
        }
    }
    if (SafeArr(r, c, n))
    {
        if (sol[r][c] == 0)
        {
            int rr = r;
            if (SafeArr(rr - 1, c, n))
            {
                if (sol[rr - 1][c] != -1)
                {
                    sol[r][c] = sol[r][c] + sol[rr - 1][c];
                }
            }
            int cc = c;
            if (SafeArr(r, cc - 1, n))
            {
                if (sol[r][cc - 1] != -1)
                {
                    sol[r][c] = sol[r][c] + sol[r][cc - 1];
                }
            }
        }
        if (Count_Paths(sol, r, c + 1, n))
        {
            return true;
        }
    }
    return true;
}
int main()
{
    int n;
    cout << "Enter number of rows and cols: " << endl;
    cin >> n;
    int **array = new int *[n];
    int **sol = new int *[n];
    for (int i = 0; i < n; i++)
    {
        array[i] = new int[n];
        sol[i] = new int[n];
    }
    int arr[16] = {
                    0, 0, 0, 0,
                    0, -1, 0, 0, 
                    -1, 0, 0, 0, 
                    0, 0, 0, 0
                    };
    int a = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "Array[" << i << "][" << j << "]=";
            cin >> array[i][j];
            sol[i][j] = array[i][j];
            a++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        int j = 0;
        if (array[i][j] == 0)
        {
            sol[i][j] = 1;
        }
        else
        {
            break;
        }
    }
    for (int j = 0; j < n; j++)
    {
        int i = 0;
        if (array[i][j] == 0)
        {
            sol[i][j] = 1;
        }
        else
        {
            break;
        }
    }
    cout << endl;
    if (Count_Paths(sol, 1, 1, n))
    {
        if (sol[n - 1][n - 1] == 0)
        {
            cout << "No optimal path found";
        }
        else
        {
            cout << "Number of optimal paths = " << sol[n - 1][n - 1];
        }
    }
}
