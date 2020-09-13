#include <bits/stdc++.h>
using namespace std;
char alpha[27];
void getResult(string s, int i, int j, int n, char *out, vector<string> &ans)
{
    if (i == n)
    {
        out[j] = '\0';
        string temp;
        int t = 0;
        while (out[t] != '\0')
        {
            temp += out[t];
            t++;
        }
        ans.push_back(temp);

        return;
    }
    int index = s[i] - '0';
    char cc = alpha[index];
    out[j] = cc;
    getResult(s, i + 1, j + 1, n, out, ans);
    if (i + 1 != n)
    {
        int index2 = s[i + 1] - '0';
        index = index * 10 + index2;
        if (index <= 26)
        {
            out[j] = alpha[index];
            getResult(s, i + 2, j + 1, n, out, ans);
        }
    }
}
int main()
{
    for (int i = 1; i <= 26; i++)
    {
        alpha[i] = 'a' + i - 1;
    }
    string s;
    cin >> s;
    vector<string> ans;
    char out[10000];
    getResult(s, 0, 0, s.length(), out, ans);
    cout << "[";
    for (int i = 0; i < ans.size(); i++)
    {
        if (i == ans.size() - 1)
            cout << ans[i];
        else
            cout << ans[i] + ", ";
    }
    cout << "]";

    return 0;
}
