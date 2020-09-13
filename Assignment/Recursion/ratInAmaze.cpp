#include <bits/stdc++.h>
using namespace std;
bool getResult(vector<vector<char>> &a, vector<vector<bool>> &out, int n, int m, int i, int j)
{
    if (i >= n or j >= m or a[i][j] == 'X')
        return false;
    if (i == n - 1 and j == m - 1)
    {
        out[i][j] = true;
        for (int x = 0; x < n; x++)
        {
            for (int y = 0; y < m; y++)
            {
                cout << out[x][y] << " ";
            }
            cout << '\n';
        }
        return true;
    }
    out[i][j] = true;
    bool right = getResult(a, out, n, m, i, j + 1);
    if (right)
        return true;
    bool left = getResult(a, out, n, m, i + 1, j);
    if (left)
        return true;
    out[i][j] = false;
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> a;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    vector<vector<bool>> out;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            out[i][j] = false;
        }
    }
    bool ans = getResult(a, out, n, m, 0, 0);
    if (!ans)
        cout << -1 << '\n';
}