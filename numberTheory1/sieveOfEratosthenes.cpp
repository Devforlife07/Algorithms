#include <bits/stdc++.h>
using namespace std;

void calPrimes(int primes[])
{
    for (int i = 3; i <= 1000000; i += 2)
    {
        primes[i] = 1;
    }
    for (int i = 2; i * i <= 1000000; i++)
    {
        for (int j = i * i; j <= 1000000; j += i)
        {
            primes[j] = 0;
        }
    }
}
int main()
{
    int n;
    cin >> n;
    int primes[1000000] = {0};
    calPrimes(primes);
    primes[1] = 0;
    primes[2] = 1;
    for (int i = 1; i <= n; i++)
    {
        if (primes[i])
            cout << i << " ";
    }
    return 0;
}
