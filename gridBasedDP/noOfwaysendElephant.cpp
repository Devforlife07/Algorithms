#include <iostream>
using namespace std;
int getResult(int a[4][4], int r, int c)
{
    if (a[0][0] == -1)
    {
        return 0;
    }
    int dp[100][100];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;

    //Initializing First Row And Column
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (a[i][j] == -1)
            {
                // cout<<"Here "<<i<<" "<<j<<endl;
                dp[i][j] = 0;
                //    break;
                continue;
            }
            else
            {
                // int sum = 0;
                //First For Every Row  Than For Column
                for (int k = i - 1; k >= 0; k--)
                {
                    // if(dp[k][j]==0){
                    if (a[k][j] == -1)
                    {
                        break;
                    }
                    else
                        dp[i][j] += dp[k][j];
                }
                for (int k = j - 1; k >= 0; k--)
                {
                    // if(dp[i][k]==0){
                    if (a[i][k] == -1)
                    {
                        break;
                    }
                    else
                        dp[i][j] += dp[i][k];
                }

                // dp[i][j] = sum;
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
    return dp[r - 1][c - 1];
}
int main()
{
    int matrix[4][4] = {{0, 0, -1, -1}, {-1, 0, 0, -1}, {0, 0, 0, 0}, {0, 0, 0, 0}};
    int ans = getResult(matrix, 4, 4);
    cout << ans << endl;
    return 0;
}
