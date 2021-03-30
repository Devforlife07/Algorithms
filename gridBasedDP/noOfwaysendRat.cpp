#include <bits/stdc++.h>
using namespace std;
int getResult(int a[4][4], int r, int c)
{
    if (a[0][0] == -1)
    {
        return 0;
    }
    int dp[100][100];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < c; i++)
    {
        if (a[0][i] == 0)
        {
            dp[0][i] = 1;
        }
        else
            break;
    }
    for (int i = 0; i < r; i++)
    {
        if (a[i][0] == 0)
        {
            dp[i][0] = 1;
        }
        else
            break;
    }
    // for(int i =0;i<r;i++){
    //     for(int j = 0;j<c;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    for (int i = 1; i < r; i++)
    {
        for (int j = 1; j < c; j++)
        {
            if (a[i][j] == 0)
            {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return a[r - 1][c - 1] == -1 ? 0 : dp[r - 1][c - 1];
}
int main()
{
    int matrix[4][4] = {{0, 0, -1, -1}, {-1, 0, 0, -1}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    int ans = getResult(matrix, 4, 4);
    cout << ans << endl;
    return 0;
}
