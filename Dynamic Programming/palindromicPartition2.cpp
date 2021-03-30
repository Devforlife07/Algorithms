#include <bits/stdc++.h>
using namespace std;
int getResult(string s, int x, int y)
{
    bool dp[100][100];
    memset(dp, false, sizeof(dp));
    for (int gap = 0; gap < s.length(); gap++)
    {
        for (int i = 0, j = gap; j < s.length(); i++, j++)
        {
            if (gap == 0)
            {
                dp[i][j] = true;
            }
            else if (gap == 1)
            {
                if (s[i] == s[j])
                {
                    dp[i][j] = true;
                }
                else
                    dp[i][j] = false;
            }
            else
            {
                if (s[i] == s[j] and dp[i + 1][j - 1] == true)
                    dp[i][j] = true;
                else
                    dp[i][j] = false;
            }
        }
    }
    // int j;
    for (int i = 0; i < s.length(); i++)
    {
        for (int j = 0; j < s.length(); j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << "***********************************************************" << endl;
    int dp2[100][100] = {0};
    int i, j;
    for (int gap = 0; gap < s.length(); gap++)
    {
        for (i = 0, j = gap; j < s.length(); i++, j++)
        {
            if (gap == 0)
            {
                dp2[i][j] = 0;
            }
            else if (gap == 1)
            {
                if (s[i] == s[j])
                    dp2[i][j] = 0;
                else
                    dp2[i][j] = 1;
            }
            else
            {
                if (dp[i][j])
                {
                    dp2[i][j] = 0;
                }
                else
                {
                    int ans = INT_MAX;
                    for (int k = i; k < j; k++)
                    {
                        ans = min(ans, dp2[i][k] + dp2[k + 1][j] + 1);
                    }
                    dp2[i][j] = ans;
                }
            }
        }
    }
    for (int i = 0; i < s.length(); i++)
    {
        for (int j = 0; j < s.length(); j++)
        {
            cout << dp2[i][j] << " ";
        }
        cout << endl;
    }
    return dp2[0][s.length() - 1];
}
int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    string s = "geeks";
    int ans = getResult(s, 0, s.length() - 1);
    cout << ans << endl;
}