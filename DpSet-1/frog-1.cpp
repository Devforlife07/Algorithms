#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll getResult(int *a, int n)
{
    ll dp[n + 1] = {0};
    dp[0] = dp[1];
    dp[2] = abs(a[2] - a[1]);
    for (int i = 3; i <= n; i++)
    {
        dp[i] = min(abs(a[i] - a[i - 1]) + dp[i - 1], abs(a[i] - a[i - 2]) + dp[i - 2]);
    }
    return dp[n];
}
int main()
{
    int n;
    cin >> n;
    int i = 1;
    int a[n + 1];
    a[0] = 0;
    int x;
    while (i <= n)
    {
        cin >> x;
        a[i] = x;
        i++;
    }
    ll ans = getResult(a, n);
    cout << ans << endl;

    return 0;
}