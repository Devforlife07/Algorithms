#include <bits/stdc++.h>
using namespace std;
void getResult(vector<int> &a, int i)
{
    if (i == a.size())
    {
        for (auto x : a)
            cout << x << ' ';
        cout << '\n';
        return;
    }
    for (int t = i; t < a.size(); t++)
    {
        if (t == i or a[t] != a[i])
        {
            swap(a[t], a[i]);
            getResult(a, i + 1);
        }
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int i = 0;
    for (auto &it : a)
    {
        cin >> it;
    }
    sort(a.begin(), a.end());
    getResult(a, 0);
    return 0;
}