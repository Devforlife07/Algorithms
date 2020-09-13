#include <bits/stdc++.h>
using namespace std;
void getResult(string &in, char *out, int i, int j, set<string> &ans)
{
    if (i == in.length())
    {
        out[j] = '\0';
        string temp = out;
        ans.insert(temp);
        return;
    }
    for (int t = i; t < in.length(); t++)
    {
        swap(in[i], in[t]);
        out[j] = in[i];
        getResult(in, out, i + 1, j + 1, ans);
        swap(in[i], in[t]);
    }
}
int main()
{
    string in;
    cin >> in;
    char out[100];
    set<string> ans;
    getResult(in, out, 0, 0, ans);
    for (auto x : ans)
    {
        cout << x << endl;
    }
    return 0;
}