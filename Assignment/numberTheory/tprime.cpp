#include <bits/stdc++.h>
#define ll long long
using namespace std;
int a[1000009] = {0};
vector<int> primes;
void fill()
{
    for (int i = 2; i <= 1000000; i++)
    {
        if (a[i] == 0)
        {
            primes.push_back(i);
            for (int j = i; j <= 1000000; j += i)
            {
                a[j] = 1;
            }
        }
    }
}
bool check(ll n)
{
    ll count = 0;
    for (auto x : primes)
    {
        if (binary_search(primes.begin(), primes.end(), n))
            return 0;
        // cout << x << " ";
        if (x * x >= n)
            break;
        else if (n % x == 0)
        {
            count++;

            while (n % x == 0)
            {
                count++;
                n /= x;
            }
        }
    }
    if (n > 2)
        count += 1;
    return count == 1;
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    fill();
    int n;
    cin >> n;
    int i = 1;
    ll temp;
    while (i <= n)
    {
        cin >> temp;

        if (check(temp))
        {
            cout << "YES" << '\n';
        }
        else
        {
            cout << "NO" << '\n';
        }
        i++;
    }

    return 0;
}