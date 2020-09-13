#include <bits/stdc++.h>
using namespace std;
const string alpha[] = {"", ".+@$", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
const string searchIn[] = {
    "prateek", "sneha", "deepak", "arnav", "shikha", "palak",
    "utkarsh", "divyam", "vidhi", "sparsh", "akku"};
void getAllStrings(char *out, vector<string> &ans)
{
    string t = out;

    for (int i = 0; i < 11; i++)
    {

        if (searchIn[i].find(t) != string::npos)
            ans.push_back(searchIn[i]);
    }
}
void getResult(string n, char *out, int i, int j, vector<string> &ans)
{
    if (n[i] == '\0')
    {
        out[j] = '\0';
        getAllStrings(out, ans);
        return;
    }
    char cc = n[i] - '0';
    for (int t = 0; alpha[cc][t] != '\0'; t++)
    {
        out[j] = alpha[cc][t];
        getResult(n, out, i + 1, j + 1, ans);
    }
}
int main()
{
    string n;
    cin >> n;
    vector<string> ans;
    char out[100];
    getResult(n, out, 0, 0, ans);
    set<string> res;
    for (auto x : ans)
        res.insert(x);
    for (auto x : res)
        cout << x << endl;

    return 0;
}