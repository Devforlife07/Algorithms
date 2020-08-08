#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll m = 1000000007;
ll b = m;
ll x, y, gcd;
void extendedEuclidean(ll a, ll b)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        gcd = a;
        return;
    }
    extendedEuclidean(b, a % b);
    ll currX = y % m;
    ll currY = ((x - ((a / b) * y) % m) + m) % m;
    x = currX;
    y = currY;
}
ll multiplicativeInverese(int n)
{
    extendedEuclidean(n, b);
    return x % m;
}
int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    ll ans = multiplicativeInverese(n);
    cout << ans << '\n';

    return 0;
}