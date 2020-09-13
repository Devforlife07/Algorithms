#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool possible(ll n, ll m, ll x, ll y, ll mid)
{
    return (mid * x <= m + (n - mid) * y);
}

int main()
{
    ll n, m, x, y;
    cin >> n >> m >> x >> y;
    ll s = 0;
    ll e = n;
    ll ans = INT_MIN;
    while (s <= e)
    {
        ll mid = (s + e) / 2;
        if (possible(n, m, x, y, mid))
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    cout << ans << endl;

    return 0;
}