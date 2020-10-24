#include <iostream>
using namespace std;
int fibRec(int n)
{
    if (n == 0 or n == 1)
        return n;
    return fibRec(n - 1) + fibRec(n - 2);
}
int fibDp(int n, int *dp)
{
    if (n == 0 or n == 1)
        return n;
    if (dp[n])
    {
        return dp[n];
    }
    else
        return dp[n] = fibDp(n - 1, dp) + fibDp(n - 2, dp);
}
int fibDpBottomUp(int n)
{

    int a[100] = {0};
    a[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        a[i] = a[i - 1] + a[i - 2];
    }
    return a[n];
}
int fibBottomUpSpaceOptimised(int n)
{
    if (n == 0 or n == 1)
        return n;
    int sum = 0;
    int a = 0;
    int b = 1;
    for (int i = 2; i < n; i++)
    {
        sum = a + b;
        a = b;
        b = sum;
    }
    return sum;
}

int main()
{
    int n;
    cin >> n;
    cout << fibRec(n) << endl;
    int dp[100] = {0};
    dp[1] = 1;
    cout << fibDp(n, dp) << endl;
    cout << fibDpBottomUp(n) << endl;
}