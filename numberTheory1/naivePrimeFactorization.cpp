#include <bits/stdc++.h>
using namespace std;
map<int, int> factors;
void getFactors(int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        int count = 0;
        while (n % i == 0)
        {
            count++;
            n /= i;
        }
        if (count > 0)
            factors.insert(make_pair(i, count));
    }
    if (n > 2)
        factors.insert(make_pair(n, 1));
}
int main()
{
    int n;
    cin >> n;
    getFactors(n);
    for (auto c : factors)
    {
        cout << c.first << " " << c.second << "\n";
    }
    return 1;
}