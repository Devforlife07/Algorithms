#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll getResult(int *a, int n, int k)
{
    ll dp[n + 1] = {0};
    for (int i = 2; i <= n; i++)
    {
        dp[i] = INT_MAX;
        for (int j = i - 1; i - j <= k and j >= 1; j--)
        {
            dp[i] = min(dp[i], dp[j] + (ll)abs(a[i] - a[j]));
        }
    }
    return dp[n];
}
int main()
{
    int n, k;
    cin >> n >> k;
    int a[n + 1];
    int i = 1;
    int x;
    while (i <= n)
    {
        cin >> x;
        a[i] = x;
        i++;
    }
    ll ans = getResult(a, n, k);
    cout << ans << endl;

    return 0;
}