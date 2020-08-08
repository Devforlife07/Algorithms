#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int n = 10000007;
bitset<n> b;
vector<int> primes;
void sieve()
{
    b.set();
    b[0] = b[1] = 0;
    for (ll i = 2; i <= n; i++)
    {
        if (b[i])
        {
            primes.push_back(i);
            for (ll j = i * i; j <= n; j += i)
            {
                b[j] = 0;
            }
        }
    }
}
int main()
{
    sieve();
    int n;
    cin >> n;
    int count = 1;

    for (int i = 0; primes[i] * primes[i] <= n; i++)
    {
        int c = 0;
        while (n % primes[i] == 0)
        {
            c++;
            n /= primes[i];
        }
        c += 1;
        count *= c;
    }
    if (n > 2)
        count *= 2;
    cout << count << endl;
}