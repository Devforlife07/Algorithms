#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin >> n;
    ll a[1000001];
    int i = 1;
    ll temp;
    while (i <= n)
    {
        cin >> temp;
        a[i] = temp;
        i++;
    }
    map<ll, ll> last;
    double sum = 0;
    i = 1;
    while (i <= n)
    {
        if (last[a[i]])
        {
            temp = (i - last[a[i]]) * (n - i + 1);
            last[a[i]] = i;
        }
        else
        {
            temp = i * (n - i + 1);
            last[a[i]] = i;
        }
        // cout<<temp<<'\n';
        sum += (2 * temp) - 1;
        i++;
    }
    // cout<<sum<<"Sum"<<'\n';
    sum /= (double)(n * n);
    cout << sum << '\n';

    return 0;
}