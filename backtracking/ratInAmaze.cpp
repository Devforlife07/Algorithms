#include <iostream>
using namespace std;
char arr[10][10] = {"000X", "0X0X", "0000", "0X00"};
bool getAns(char a[10][10], int out[10][10], int i, int j, int m, int n, int count)
{
    if (i == m and j == n)
    {
        count += 1;
        out[i][j] = 1;
        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                cout << out[i][j] << " ";
            }
            cout << '\n';
        }
        cout << "\n";
        return true;
    }
    if (i > m || j > n || a[i][j] == 'X')
    {
        return false;
    }
    out[i][j] = 1;
    bool rightans = getAns(a, out, i, j + 1, m, n, count);
    bool downans = getAns(a, out, i + 1, j, m, n, count);
    out[i][j] = 0;
    if (rightans || downans)
        return true;
    return false;
}
int main()
{
    int out[10][10] = {0};
    int count = 0;
    bool ans = getAns(arr, out, 0, 0, 3, 3, count);
    if (!ans)
        cout << "No Path Exists" << '\n';
    else
        cout << count << '\n';
    return 0;
}