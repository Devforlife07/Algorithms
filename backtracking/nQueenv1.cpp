#include <bits/stdc++.h>
using namespace std;
bool a[100][100];
bool isValid(int x, int y, int n)
{
    //Check column
    for (int i = 0; i < x; i++)
    {

        if (a[i][y])
        {

            return false;
        }
    }
    //Left Diagonal
    int i = x;
    int j = y;
    while (i >= 0 and j >= 0)
    {
        if (a[i][j])
            return false;
        i--;
        j--;
    }
    i = x;
    j = y;
    while (i >= 0 and j < n)
    {
        if (a[i][j])
            return false;
        i--;
        j++;
    }
    return true;
}
bool getResult(int n, int i)
{
    if (i >= n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cout << a[i][j] << " ";
            cout << endl;
        }
        return true;
    }

    for (int l = 0; l < n; l++)
    {
        if (isValid(i, l, n))
        {

            a[i][l] = true;
            bool next = getResult(n, i + 1);
            if (next)
                return true;
            a[i][l] = false;
        }
    }
    return false;
}
int main()
{
    memset(a, false, sizeof(a));
    int n;
    cin >> n;
    getResult(n, 0);
    return 0;
}