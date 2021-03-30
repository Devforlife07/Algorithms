#include <bits/stdc++.h>
using namespace std;
int getResultOptimised(string s)
{
    int isPalin[100][100];
    for (int gap = 0; gap < s.length(); gap++)
    {
        for (int i = 0, j = gap; j < s.length(); i++, j++)
        {
            if (gap == 0)
            {
                isPalin[i][j] = true;
            }
            else if (gap == 1)
            {
                if (s[i] == s[j])
                {
                    isPalin[i][j] = true;
                }
                else
                    isPalin[i][j] = false;
            }
            else
            {
                if ((s[i] == s[j]) and isPalin[i + 1][j - 1] == true)
                {
                    isPalin[i][j] = true;
                }
                else
                    isPalin[i][j] = false;
            }
        }
    }
    for (int i = 0; i < s.length(); i++)
    {
        for (int j = 0; j < s.length(); j++)
        {
            cout << isPalin[i][j] << " ";
        }
        cout << endl;
    }
    int dp[100] = {0};
    dp[0] = 0;
    for (int i = 1; i < s.length(); i++)
    {
        if (isPalin[0][i])
        {
            dp[i] = 0;
        }
        else
        {
            int minimum = INT_MAX;
            for (int j = i; j >= 1; j--)
            {
                if (isPalin[j][i])
                {
                    minimum = min(minimum, dp[j - 1]);
                }
            }
            dp[i] = minimum + 1;
        }
    }
    //   for(auto x: dp){
    //       cout<<x<<" ";
    //   }
    //   cout<<'\n';
    return dp[s.length() - 1];
}
int main()
{
    string s = "devansh";
    int ans = getResultOptimised(s);
    cout << ans << endl;
}
