#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;
vector<vector<ll>> multiply(vector<vector<ll>> K, vector<vector<ll>> L)
{
    vector<vector<ll>> res(3, vector<ll>(3));
    for (int i = 1; i <= 2; i++)
    {
        for (int j = 1; j <= 2; j++)
        {
            for (int k = 1; k <= 2; k++)
            {
                res[i][j] = (res[i][j] + (K[i][k] * L[k][j]) % MOD) % MOD;
            }
        }
    }
    return res;
}
vector<vector<ll>> pow(vector<vector<ll>> T, ll power)
{
    if (power == 1)
        return T;
    else if (power & 1)
        return multiply(T, pow(T, power - 1));
    else
    {
        vector<vector<ll>> X = pow(T, power / 2);
        return multiply(X, X);
    }
}
ll getRes(ll n)
{
    if (n <= 2)
        return 1;
    vector<ll> fi(3, 0);
    fi[1] = 1;
    fi[2] = 1;
    // for (ll x : fi)
    //     cout << x << ' ';
    // cout << '\n';
    vector<vector<ll>> T(3, vector<ll>(3));
    T[1][1] = 0;
    T[1][2] = 1;
    T[2][1] = 1;
    T[2][2] = 1;

    vector<vector<ll>> res = pow(T, n - 2);
    // for (int i = 1; i <= 2; i++)
    // {
    //     for (int j = 1; j <= 2; j++)
    //         cout << res[i][j] << " ";
    //     cout << '\n';
    // }
    ll ans = 0;
    for (int i = 1; i <= 2; i++)
    {
        ans = (ans + (res[2][i] * fi[i]) % MOD) % MOD;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        cout << getRes(n) << '\n';
    }

    return 0;
}