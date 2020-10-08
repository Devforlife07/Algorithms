#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll fromCentre(ll *a, int l, int r)
{
    int mid = (l + r) / 2;
    int l_max = INT32_MIN;
    int r_max = INT32_MIN;
    int sum1 = 0;
    int sum2 = 0;
    for (int i = mid; i >= l; i--)
    {
        sum1 += a[i];
        if (sum1 > l_max)
        {
            l_max = sum1;
        }
    }
    for (int i = mid + 1; i <= r; i++)
    {
        sum2 += a[i];
        if (sum2 > r_max)
        {
            r_max = sum2;
        }
    }
    return max(sum1 + sum2, max(l_max, r_max));
}
ll getResult(ll *a, int l, int r)
{
    if (l == r)
        return a[l];
    int mid = (l + r) / 2;
    ll ans1 = getResult(a, l, mid);
    ll ans2 = getResult(a, mid + 1, r);
    ll ans3 = fromCentre(a, l, r);
    return max(ans1, max(ans2, ans3));
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        ll *a = new ll[n];
        int i = 0;
        ll temp;
        while (i < n)
        {
            cin >> temp;
            a[i] = temp;
            i++;
        }
        ll ans = getResult(a, 0, n - 1);
        cout << ans << '\n';
    }

    return 0;
#include <bits/stdc++.h>
    using namespace std;
#define ll long long
    ll fromCentre(ll * a, int l, int r)
    {
        int mid = (l + r) / 2;
        int l_max = INT32_MIN;
        int r_max = INT32_MIN;
        int sum1 = 0;
        int sum2 = 0;
        for (int i = mid; i >= l; i--)
        {
            sum1 += a[i];
            if (sum1 > l_max)
            {
                l_max = sum1;
            }
        }
        for (int i = mid + 1; i <= r; i++)
        {
            sum2 += a[i];
            if (sum2 > r_max)
            {
                r_max = sum2;
            }
        }
        return max(l_max + r_max, max(l_max, r_max));
    }
    ll getResult(ll * a, int l, int r)
    {
        if (l == r)
            return a[l];
        int mid = (l + r) / 2;
        ll ans1 = getResult(a, l, mid);
        ll ans2 = getResult(a, mid + 1, r);
        ll ans3 = fromCentre(a, l, r);
        return max(ans1, max(ans2, ans3));
    }
    int main()
    {
        int t;
        cin >> t;
        while (t--)
        {
            int n;
            cin >> n;
            ll *a = new ll[n];
            int i = 0;
            ll temp;
            while (i < n)
            {
                cin >> temp;
                a[i] = temp;
                i++;
            }
            ll ans = getResult(a, 0, n - 1);
            cout << ans << '\n';
        }

        return 0;
    }
}