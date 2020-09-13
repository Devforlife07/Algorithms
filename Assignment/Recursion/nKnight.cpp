#include <bits/stdc++.h>
using namespace std;
const int xMove[8] = {2, 1, -1, -2, -2, -1, 1, 2};
const int yMove[8] = {1, 2, 2, 1, -1, -2, -2, -1};
bool isValid(bool a[][1000], int i, int j, int n)
{
    if (i >= n or i < 0 or j >= n or j < 0 or a[i][j])
        return false;
    for (int k = 0; k < 8; k++)
    {
        if (i + xMove[k] < n and i + xMove[k] >= 0 and j + yMove[k] >= 0 and j + yMove[k] < n and a[i + xMove[k]][j + yMove[k]])
            return false;
    }
    return true;
}
void getResult(bool a[][1000], int i, int j, int n, int &ans, int count)
{
    if (count < 0)
        return;
    if (i == n)
        return;
    if (count == 0)
    {
        ans++;
        // cout << "gap";
        for (int k = 0; k < n; k++)
        {
            for (int l = 0; l < n; l++)
            {
                if (a[k][l])
                {
                    cout << '{' << k << '-' << l << '}' << " ";
                }
            }
        }
        return;
    }
    if (j == n)
    {
        // cout << (i + 1) << " " << j << endl;
        return getResult(a, i + 1, 0, n, ans, count);
    }
    for (int k = i; k < n; k++)
    {
        for (int l = j; l < n; l++)
        {
            if (isValid(a, k, l, n))
            {

                a[k][l] = 1;
                // cout << k << " " << l << " " << endl;
                count--;
                getResult(a, k, l + 1, n, ans, count);
                // if (curr)
                // return true;

                a[k][l] = 0;
                count++;
            }
        }
    }
    // return false;
}
int main()
{
    int n;
    cin >> n;
    bool a[n][1000];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = 0;
        }
    }
    int ans = 0;
    getResult(a, 0, 0, n, ans, n);
    cout << '\n';
    cout << ans << endl;

    return 0;
}