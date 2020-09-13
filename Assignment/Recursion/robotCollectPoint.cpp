#include <bits/stdc++.h>
using namespace std;
int secondary[15][5];
int sum = 0;
void fillSecondary(int a[][5], int t, int h)
{
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (i >= t - 4 and i <= t and a[i][j] == -1)
            {
                secondary[i][j] = 0;
            }
            else
                secondary[i][j] = a[i][j];
        }
    }
}
int getResult(int a[][5], int h, int i, int j, int sum)
{
    if (i < 0 || j < 0 || j >= 5)
        return INT32_MIN;
    if (i == 0)
        return a[i][j];

    int ans1 = getResult(a, h, i - 1, j - 1, sum);
    int ans2 = getResult(a, h, i - 1, j, sum);
    int ans3 = getResult(a, h, i - 1, j + 1, sum);
    ;
    return a[i][j] + max(ans1, max(ans2, ans3));
}
void solve()
{
    int h;
    cin >> h;
    int a[h][5];
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> a[i][j];
        }
    }
    if (h <= 5)
    {
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (a[i][j] == -1)
                {
                    a[i][j] = 0;
                }
            }
        }
        int op1 = getResult(a, h, h - 1, 1, 0);
        int op2 = getResult(a, h, h - 1, 2, 0);
        int op3 = getResult(a, h, h - 1, 3, 0);
        cout << max(op1, max(op2, op3)) << '\n';
    }
    else
    {
        int ans = INT32_MIN;
        for (int t = 4; t <= h; t++)
        {
            fillSecondary(a, t, h);
            int op1 = getResult(secondary, h, h - 1, 1, 0);
            int op2 = getResult(secondary, h, h - 1, 2, 0);
            int op3 = getResult(secondary, h, h - 1, 3, 0);
            int curr_max = max(op1, max(op2, op3));
            ans = max(ans, curr_max);
        }
        cout << ans << '\n';
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}