#include <bits/stdc++.h>
using namespace std;
bool isPalindrome(string s, int i, int j)
{
    while (i < j)
    {
        if (s[i] != s[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}
int getResult(string s, int i, int j)
{
    if (i >= j or isPalindrome(s, i, j))
        return 0;
    int ans = INT_MAX;
    for (int k = i; k < j; k++)
    {
        ans = min(ans, getResult(s, i, k) + getResult(s, k + 1, j) + 1);
    }
    return ans;
}
int dpSolution(string str)
{
    int n = str.length();
    bool dp[n][n];
    memset(dp, false, sizeof(dp));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    string s = "abcccbr";
    int ans = getResult(s, 0, s.length() - 1);
    cout << ans << endl;
    return 0;
}
