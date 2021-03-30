#include <bits/stdc++.h>
// #define n 6
using namespace std;
int getResult(int a[1005][1005], int n)
{
    int dp[n][n];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = a[0][0];
    //initializing first row and column
    for (int i = 1; i < n; i++)
    {
        dp[0][i] = dp[0][i - 1] + a[0][i];
    }
    for (int i = 1; i < n; i++)
    {
        dp[i][0] = dp[i - 1][0] + a[i][0];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + a[i][j];
        }
    }
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    int sum1, sum2, sum3, sum4;
    int ans = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sum1 = dp[i][j];
            sum2 = dp[i][n - 1] - sum1;
            sum3 = dp[n - 1][j] - sum1;
            sum4 = dp[n - 1][n - 1] - sum1 - sum2 - sum3;
            // cout << sum1 << " " << sum2 << " " << sum3 << " " << sum4 << endl;
            ;
            ans = max(ans, min(sum1, min(sum2, min(sum3, sum4))));
            // cout << ans << endl;
        }
    }
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return ans;
}
int main()
{
    int n, g;
    cin >> n >> g;
    int x, y;
    int a[1005][1005];
    memset(a, 0, sizeof(a));
    int i = 1;
    while (i <= g)
    {
        cin >> x >> y;
        a[x - 1][y - 1] = 1;
        i++;
    }
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << a[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    int ans = getResult(a, n);
    cout << ans << endl;
    return 0;
}