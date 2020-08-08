#include <bits/stdc++.h>
using namespace std;
void getResult(char *a, int i, set<string> &s)
{
    if (a[i] == '\0')
    {
        string t(a);
        s.insert(t);
        return;
    }
    for (int x = i; a[x] != '\0'; x++)
    {
        swap(a[i], a[x]);
        getResult(a, i + 1, s);
        swap(a[i], a[x]);
    }
}
int main()
{
    set<string> st;
    char a[1000];
    cin >> a;
    getResult(a, 0, st);
    for (auto x : st)
        cout << x << '\n';

    return 0;
}