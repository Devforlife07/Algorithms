#include <iostream>
#include <vector>
using namespace std;
#define ll long long
#define MOD 1000000000
vector<ll> a, b, c;
ll n;
ll k;
vector<vector<ll>> multiply(vector<vector<ll>> L, vector<vector<ll>> K)
{
    vector<vector<ll>> res(k + 1, vector<ll>(k + 1));
    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            for (int x = 1; x <= k; x++)
            {
                res[i][j] = (res[i][j] + (L[i][x] * K[x][j]) % MOD) % MOD;
            }
        }
    }
    return res;
}
vector<vector<ll>> pow(vector<vector<ll>> T, int n)
{
    if (n == 1)
        return T;
    else if (n & 1)
    {
        return multiply(T, pow(T, n - 1));
    }
    vector<vector<ll>> sum = pow(T, n / 2);
    return multiply(sum, sum);
}
int compute(int k)
{
    if (n == 0)
        return 0;
    if (n < k)
    {
        return b[n - 1];
    }
    vector<ll> fi(k + 1);
    for (int i = 1; i <= k; i++)
    {
        fi[i] = b[i - 1];
    }
    vector<vector<ll>> T(k + 1, vector<ll>(k + 1));
    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (i < k)
            {
                if (j == (i + 1))
                    T[i][j] = 1;
                else
                    T[i][j] = 0;
            }
            else
            {
                T[i][j] = c[k - j];
            }
        }
    }
    T = pow(T, n - 1);
    ll sum = 0;
    for (int i = 1; i <= k; i++)
    {
        sum = (sum + (T[1][i] * fi[i]) % MOD) % MOD;
    }
    return sum;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie();
    int t;
    cin >> t;
    while (t--)
    {
        ll num;
        cin >> k;
        int i = 0;
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
        cin >> n;
        cout << compute(k) << "\n";
        b.clear();
        c.clear();
    }
}