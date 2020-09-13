#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    int c = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int dp[n][2];
        dp[0][0] = {1};
        dp[0][1] = {1};
        for (int i = 1; i < n; i++)
        {
            dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
            dp[i][1] = dp[i - 1][0];
        }
        int ans = dp[n - 1][0] + dp[n - 1][1];
        cout << "#" << c << " "
             << ": " << ans << '\n';
        c++;
    }
    return 0;
}