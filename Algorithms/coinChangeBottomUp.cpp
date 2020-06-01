#include <bits/stdc++.h>
using namespace std;
int getResult(int coins[], int amount)
{
    int *dp = new int[amount + 1];
    for (int i = 0; i <= amount; i++)
    {
        dp[i] = INT_MAX;
    }
    dp[0] = 0;
    for (int rs = 1; rs <= amount; rs++)
    {
        for (int i = 0; i < 10; i++)
        {
            if (coins[i] <= rs)
            {
                int smallAns = dp[rs - coins[i]];
                if (smallAns != INT_MAX)
                {
                    dp[rs] = min(dp[rs], smallAns + 1);
                }
            }
        }
    }
    return dp[amount];
}
int main()
{
    int n;
    cin >> n;
    int coins[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
    int ans = getResult(coins, n);
    cout << ans << '\n';
    return 0;
}