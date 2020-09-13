#include <bits/stdc++.h>
using namespace std;
bool getResult(int *a, int n, int i, int sum, int cnt)
{
    if (i == -1)
    {
        if (sum == 0 and cnt > 0)
            return true;
        else
            return false;
    }
    return getResult(a, n, i - 1, sum, cnt) || getResult(a, n, i - 1, sum + a[i], cnt + 1);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        int i = 0;
        while (i < n)
        {
            cin >> a[i];
            i++;
        }
        int ans = getResult(a, n, n - 1, 0, 0);
        if (ans)
            cout << "Yes" << '\n';
        else
            cout << "No" << '\n';
    }

    return 0;
}