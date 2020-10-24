#include <iostream>
using namespace std;
int getResult(int *a, int i, int j, int y, int dp[][100])
{
    if (i == j)
        return y * a[i];
    if (dp[i][j] != 0)
        return dp[i][j];
    int op1 = a[i] * y + getResult(a, i + 1, j, y + 1, dp);
    int op2 = a[j] * y + getResult(a, i, j - 1, y + 1, dp);
    return dp[i][j] = max(op1, op2);
}
int main()
{
    int a[] = {2, 1, 3, 5, 1};
    int n = sizeof(a) / sizeof(a[0]);
    int dp[100][100] = {0};
    int ans = getResult(a, 0, n - 1, 1, dp);
    cout << ans << endl;
}
