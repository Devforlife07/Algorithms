#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> res;
void getResult(int n, int *a, vector<int> &ans, bool *taken, int target, int curr, int limit)
{
    if (limit < 0)
        return;
    if (curr > target)
        return;
    if (curr == target)
    {
        res.push_back(ans);
        return;
    }
    for (int i = limit; i >= 0; i--)
    {
        if (taken[i])
            continue;
        int now = a[i];
        if (now + curr <= target)
        {
            curr += now;
            taken[i] = true;
            ans.push_back(a[i]);
            getResult(n, a, ans, taken, target, curr, i);
            curr -= now;
            ans.pop_back();
            taken[i] = false;
        }
    }
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n, greater<int>());
    int target;
    cin >> target;
    vector<int> ans;
    bool taken[n];
    set<vector<int>> s;
    for (int i = 0; i < n; i++)
        taken[i] = false;
    getResult(n, a, ans, taken, target, 0, n - 1);
    sort(res.begin(), res.end());
    for (int i = 0; i < res.size(); i++)
    {
        s.insert(res[i]);
    }
    for (auto x : s)
    {
        for (int i = 0; i < x.size(); i++)
        {
            cout << x[i] << " ";
        }
        cout << endl;
    }
    return 0;
}