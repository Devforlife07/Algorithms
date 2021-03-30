#include <bits/stdc++.h>
#define MOD 100
using namespace std;
int getResult(int a[10000], int n)
{
    int smoke[n + 1][n + 1];
    int cost[n + 1][n + 1];
    memset(smoke, 0, sizeof(smoke));
    memset(cost, 0, sizeof(cost));
    //Initializing both smoke and cost
    for (int i = 1; i <= n; i++)
    {
        cost[i][i] = a[i];
    }
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {
    //         cout << cost[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    for (int gap = 1; gap <= n; gap++)
    {
        for (int i = 1, j = gap + 1; j <= n; i++, j++)
        {
            if (gap == 1)
            {
                cost[i][j] = (a[i] + a[j]) % MOD;
                smoke[i][j] = (a[i] * a[j]);
            }
            else
            {
                int ans = INT_MAX;
                int ans2 = INT_MAX;
                for (int k = i; k < j; k++)
                {
                    ans = min(ans, smoke[i][k] + smoke[k + 1][j] + cost[i][k] * cost[k + 1][j]);
                    ans2 = min(ans2, (cost[i][k] + cost[k + 1][j]) % MOD);
                }
                smoke[i][j] = ans;
                cost[i][j] = ans2;
            }
        }
    }
    // for(int i = 1;i<=n;i++){
    //     for(int j = 1;j<=n;j++){
    //         cout<<smoke[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    //     for(int i = 1;i<=n;i++){
    //     for(int j = 1;j<=n;j++){
    //         cout<<cost[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    return smoke[1][n];
}
int main()
{
    int n;
    while (cin >> n)
    {

        int a[10000];
        int i = 1;
        while (i <= n)
        {
            cin >> a[i];
            i++;
        }
        int ans = getResult(a, n);
        cout << ans << endl;
    }
    return 0;
}
