#include <bits/stdc++.h>
#define ll long long
using namespace std;
int getResult(int n)
{
    if (n == 1)
        return 0;
    int result = n;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            result /= (i);
            result *= (i - 1);
            while (n % i == 0)
            {
                n /= i;
            }
        }
    }
    if (n > 2)
    {
        result /= n;
        result *= n - 1;
    }
    return result;
}
int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int ans = getResult(n);
    cout << ans << '\n';

    return 0;
}