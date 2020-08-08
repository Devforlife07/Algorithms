#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long
vector<ll> a, b, c;
int k;
vector<vector<ll>> mul(vector<vector<ll>> K, vector<vector<ll>> L, ll mod)
{
    vector<vector<ll>> res(k + 2, vector<ll>(k + 2));
    for (ll i = 1; i <= k + 1; i++)
    {
        for (ll j = 1; j <= k + 1; j++)
        {
            for (ll x = 1; x <= k + 1; x++)
            {
                res[i][j] = (res[i][j] + (K[i][x] * L[x][j]) % mod) % mod;
            }
        }
    }
    return res;
}
vector<vector<ll>> pow(vector<vector<ll>> T, ll n, ll mod)
{

    if (n == 1)
        return T;
    else if (n & 1)
        return mul(T, pow(T, n - 1, mod), mod);
    vector<vector<ll>> sum = pow(T, n / 2, mod);
    return mul(sum, sum, mod);
}

ll compute(ll n, ll m)
{

    vector<ll> fi(k + 2);
    ll sumk = 0;
    if (n == 0)
        return 0;
    if (n <= k)
    {
        for (ll i = 0; i < n; i++)
        {

            sumk = (sumk + b[i]) % m;
        }
        sumk %= m;
        return sumk;
    }
    ll i = 0;
    //calculate sum of first k elements
    for (i = 0; i < k; i++)
    {
        sumk = (sumk + b[i]) % m;
    }
    //Construct Fi Vector
    fi[1] = sumk;
    for (i = 2; i <= k + 1; i++)
    {
        fi[i] = b[i - 2];
    }

    vector<vector<ll>> T(k + 2, vector<ll>(k + 2));
    for (i = 1; i <= k + 1; i++)
    {
        for (ll j = 1; j <= k + 1; j++)
        {
            if (i == 1)
            {
                if (j == 1)
                    T[i][j] = 1;
                else
                {
                    T[i][j] = c[k - j + 1];
                }
            }
            else if (i == k + 1)
            {
                if (j == 1)
                    T[i][j] = 0;
                else
                {
                    T[i][j] = c[k - j + 1];
                }
            }
            else
            {
                if (j == (i + 1))
                    T[i][j] = 1;
                else
                {
                    T[i][j] = 0;
                }
            }
        }
    }

    vector<vector<ll>> res = pow(T, n - k, m);

    // for (int i = 1; i <= k + 1; i++)
    // {
    //     for (int j = 1; j <= k + 1; j++)
    //         cout << [i][j] << " ";
    //     cout << '\n';
    // }
    ll answer = 0;
    for (ll t = 1; t <= k + 1; t++)
    {
        answer = (answer % m + (res[1][t] * fi[t]) % m) % m;
    }
    return answer;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {

        cin >> k;
        int i = 0;
        ll num = 0l;
        while (i < k)
        {
            cin >> num;
            b.push_back(num);
            i++;
        }
        i = 0;
        while (i < k)
        {
            cin >> num;
            c.push_back(num);
            i++;
        }
        ll m, n, p;
        cin >> m >> n >> p;
        ll ans = (compute(n, p) % p - compute(m - 1, p) % p + p) % p;
        // if (ans <= 0)
        //     cout << (ans + p) % p << "\n";
        // else
            cout << ans << "\n";
        b.clear();
        c.clear();
    }
}