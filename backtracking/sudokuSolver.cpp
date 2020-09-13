#include <bits/stdc++.h>
using namespace std;
bool check(int a[9][9], int i, int j, int num)
{
    for (int t = 0; t < 9; t++)
    {
        if (a[i][t] == num || a[t][j] == num)
            return false;
    }
    int sx = (i / 3) * 3;
    int sy = (j / 3) * 3;
    for (int k = sx; k < sx + 3; k++)
    {
        for (int l = sy; l < sy + 3; l++)
        {
            if (a[k][l] == num)
                return false;
        }
    }
    return true;
}
bool getResult(int a[9][9], int n, int m, int i, int j)
{

    if (i == 9)
    {
        for (int k = 0; k < n; k++)
        {
            for (int l = 0; l < m; l++)
            {
                cout << a[k][l] << " ";
            }
            cout << '\n';
        }
        return true;
    }
    if (j == 9)
    {
        return getResult(a, n, m, i + 1, 0);
    }
    if (a[i][j] != 0)
    {
        return getResult(a, n, m, i, j + 1);
    }
    for (int t = 1; t <= 9; t++)
    {
        if (check(a, i, j, t))
        {
            a[i][j] = t;
            bool next = getResult(a, n, m, i, j + 1);
            if (next)
                return true;
        }
    }
    a[i][j] = 0;
    return false;
}
int main()
{
    int n = 9;
    int m = 9;
    int a[9][9] = {{3, 1, 6, 5, 7, 8, 4, 9, 2},
                   {5, 2, 9, 1, 3, 4, 7, 6, 8},
                   {4, 8, 7, 6, 2, 9, 5, 3, 1},
                   {2, 6, 3, 0, 1, 5, 9, 8, 7},
                   {9, 7, 4, 8, 6, 0, 1, 2, 5},
                   {8, 5, 1, 7, 9, 2, 6, 4, 3},
                   {1, 3, 8, 0, 4, 7, 2, 0, 6},
                   {6, 9, 2, 3, 5, 1, 8, 7, 4},
                   {7, 4, 5, 0, 8, 6, 3, 1, 0}};

    bool ans = getResult(a, n, m, 0, 0);
    if (!ans)
        cout << "No Solution Exists" << '\n';

    return 0;
}