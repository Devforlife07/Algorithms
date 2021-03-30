//Problem Link https://hack.codingblocks.com/app/contests/1310/546/problem
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int getResult(int n, int x, int y, int z)
{
    ll dp[n + 1];
    memset(dp, 0, sizeof(dp));
    //Base Cases
    dp[0] = 0;
    dp[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        //If i is odd
        if (i % 2)
        {
            dp[i] = min(dp[i - 1] + y, (dp[(i + 1) / 2] + x + z));
        }
        else
        {
            dp[i] = min(dp[i - 1] + y, (dp[i / 2] + x));
        }
    }
    // for(int i = 0;i<=n;i++){
    //     cout<<dp[i]<<" ";
    // }
    // cout<<endl;
    return dp[n];
}
int main()
{
    int n;
    cin >> n;
    int x, y, z;
    cin >> x >> y >> z;
    ll ans = getResult(n, x, y, z);
    cout << ans << endl;
    return 0;
}