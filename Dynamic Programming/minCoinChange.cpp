#include <bits/stdc++.h>
using namespace std;
int getResult(int *coins, int amount, int n)
{
    if (amount == 0)
    {
        return 0;
    }
    int curr = INT_MAX, curr_max = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (coins[i] <= amount)
        {
            curr_max = getResult(coins, amount - coins[i], n);
        }
        if (curr_max != INT_MAX and curr_max + 1 < curr)
        {
            curr = curr_max + 1;
        }
    }
    return curr;
}
int minCoinBottomUp(int *coins, int amount, int n)
{
    long long dp[1001];
    for (int i = 0; i <= 1000; i++)
    {
        dp[i] = INT_MAX;
    }
    dp[0] = 0;
    for (int i = 1; i <= amount; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (coins[j] <= i)
            {
                int res = dp[i - coins[j]];
                if (res != INT_MAX and res + 1 < dp[i])
                {
                    dp[i] = res + 1;
                }
            }
        }
    }
    return dp[amount];
}
int minCoinChangeTopDown(int *coins, int amount, int n, int *dp)
{
    if (amount == 0)
    {
        return 0;
    }
    if (dp[amount] != 0)
    {
        return dp[amount];
    }
    int curr_max = INT_MAX;
    int curr = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (coins[i] <= amount)
        {
            curr_max = minCoinChangeTopDown(coins, amount - coins[i], n, dp);
        }
        if (curr_max != INT_MAX and curr_max + 1 < curr)
        {
            curr = curr_max + 1;
        }
    }
    return dp[amount] = curr;
}
int main()
{
    int coins[] = {1, 2, 5, 10, 20};
    int amount = 104;
    int n = sizeof(coins) / sizeof(int);
    int ans = minCoinBottomUp(coins, amount, n);
    int dp[1000] = {0};
    int ans2 = minCoinChangeTopDown(coins, amount, n, dp);
    cout << ans << endl;
    cout << ans2 << endl;

    return 0;
}