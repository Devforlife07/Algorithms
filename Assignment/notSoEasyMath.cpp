#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    cin >> t;
    while (t)
    {
        ll n;
        cin >> n;
        ll ans = 0;
        int primes[] = {2, 3, 5, 7, 11, 13, 17, 19};
        ll subset = 1 << 8;
        for (ll i = 1; i < subset; i++)
        {
            int curr = i;
            int val = __builtin_popcount(i);
            ll prod = 1;
            for (ll j = 0; j <= 7; j++)
            {
                if (curr & 1)
                {
                    prod *= primes[j];
                }
                curr = curr >> 1;
            }
            if (val & 1)
            {
                ans += (n / prod);
            }
            else
            {
                ans -= n / prod;
            }
        }
        cout << ans << '\n';
        t--;
    }

    return 0;
}