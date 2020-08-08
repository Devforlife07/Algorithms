#include <iostream>
#include <stdlib.h>
#include <cstring>

#define ff first
#define se second
#define pb push_back
#define nn 100010
#define mt make_tuple
#define mp make_pair
#define ll long long int
using namespace std;

ll a[nn], pre[nn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    // cout.tie(0);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("out.txt", "w", stdout);
    // #endif
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        ll sum = 0;
        memset(pre, 0, sizeof pre);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
            sum %= n;
            sum = (sum + n) % n;
            pre[sum]++;
        }
        ll ans = (pre[0] * (pre[0] + 1)) / 2;
        for (int i = 1; i < n; i++)
        {
            ans += (pre[i] * (pre[i] - 1)) / 2;
        }
        cout << ans << endl;
    }
    return 0;
}
