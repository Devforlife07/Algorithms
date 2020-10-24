#include <bits/stdc++.h>
using namespace std;
int recursiveSolution(int *rod, int n, int length)
{
    if (length <= 0)
    {
        return 0;
    }
    int ans = INT_MIN;
    // for (int i = 0; i < length; i++)
    for (int i = 0; i < n; i++)
    {
        if (length - i - 1 >= 0)
            ans = max(ans, rod[i] + recursiveSolution(rod, n, length - i - 1));
    }
    return ans;
}
int dpSolution(int *rod, int length)
{
    int dp[100] = {0};
    for (int i = 1; i <= length; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            dp[i] = max(dp[i], rod[j - 1] + dp[i - j]);
        }
    }
    return dp[length];
}
int main()
{
    int rod[] = {2, 3, 5, 7, 9, 11};
    int n = sizeof(rod) / sizeof(int);
    int length = n;
    int ans = recursiveSolution(rod, n, length);
    cout << ans << '\n';
    int ans2 = dpSolution(rod, length);
    cout << ans2 << endl;
}