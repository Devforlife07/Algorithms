#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        double res = 0.0;
        for (int i = 1; i <= n; i++)
        {
            res += ((double)n / i) * 1.0;
        }
        cout << fixed << setprecision(2) << res << "\n";
    }

    return 0;
}