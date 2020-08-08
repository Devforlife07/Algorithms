#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll m = 1000000007;
ll moduloExponentiation(ll a, ll pow)
{
    ll temp = pow;
    ll ans = 1;
    while (temp > 0)
    {
        if (temp & 1)
        {
            ans = ((ans % m) * (a % m)) % m;
        }
        temp >>= 1;
        a = (a * a) % m;
    }
    return ans;
}
ll multiplicativeInverese(ll n, ll pow)
{
    ll ans = moduloExponentiation(n, pow);
    return ans % m;
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    ll ans = multiplicativeInverese(n, m - 2);
    cout << ans << '\n';

    return 0;
}