//stairs problem O(N) using bottom up dp and slding window concept

#include <iostream>
using namespace std;
int bottomUpDp(int n, int k)
{
    int *dp = new int[n];
    dp[0] = 1;
    int temp = 0;
    for (int step = 1; step <= n; step++)
    {
        dp[step] = 0;
        temp += dp[step - 1];
        dp[step] = temp;
        if (step - k >= 0)
            temp -= dp[step - k];
    }
    return dp[n];
}

int main()
{
    // your code goes here
    int n, k;
    cin >> n >> k;
    cout << bottomUpDp(n, k);
    return 0;
}
