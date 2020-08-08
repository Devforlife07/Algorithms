#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int size = 1000005;
bitset<size> primes;
void calPrimes()
{  
    for (int i = 3; i < size; i += 2)
    {
        primes[i] = 1;
    }
    for (ll i = 3; i * i < size; i += 2)
    {
        if (primes[i])
        {
            for (ll j = i * i; j < size; j += i)
            {
                primes[j] = 0;
            }
        }
    }
    primes[1] = 0;
    primes[2] = 1;
}
int main()
{
    int t;
    cin >> t;
    calPrimes();
    int csums[size] = {0};
    for (int i = 1; i < size; i++)
    {
        csums[i] = csums[i - 1] + primes[i];
    }
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        cout << csums[b] - csums[a - 1] << '\n';
    }
    return 0;
}