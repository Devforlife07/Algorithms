#include <bits/stdc++.h>
using namespace std;
int topdown(int n, int k, int *dp)
{
    if (n == 0)
        return 1;
    if (n < 0)
        return 0;
    if (dp[n])
    {
        return dp[n];
    }
    int ans = 0;
    for (int i = 1; i <= k; i++)
    {
        ans += topdown(n - i, k, dp);
    }
    return dp[n] = ans;
}
int main()
{
    int n, k;
    cin >> n >> k;
    int dp[100] = {0};
    int ans = topdown(n, k, dp);
    cout << ans << endl;

    return 0;
}