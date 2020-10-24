#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int getResult(int *a, int n)
{
    int dp[100] = {0};
    dp[0] = a[0] > 0 ? a[0] : 0;
    int maxtillnow = INT_MIN;
    for (int i = 1; i < n; i++)
    {
        dp[i] = dp[i - 1] + a[i];
        if (dp[i] < 0)
        {
            dp[i] = 0;
        }
        maxtillnow = max(dp[i], maxtillnow);
    }
    return maxtillnow;
}
int kadaneAlgoritm(int *a, int n)
{
    int curr = 0;
    int maxtillnow = 0;
    for (int i = 0; i < n; i++)
    {
        curr += a[i];
        if (curr < 0)
        {
            curr = 0;
        }
        maxtillnow = max(curr, maxtillnow);
    }
    return maxtillnow;
}
int main()
{
    int a[] = {-2, 4, -1, 5, 1, -7, 8};
    int n = sizeof(a) / sizeof(a[0]);
    int ans = getResult(a, n);
    cout << ans << endl;
    int ans2 = kadaneAlgoritm(a, n);
    cout << ans2 << endl;
    return 0;
}
