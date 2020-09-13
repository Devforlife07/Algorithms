#include <bits/stdc++.h>
using namespace std;
double getResult(int n, int p)
{
    int s = 0;
    int e = n;
    double res = 0;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (mid * mid == s)
            return mid;
        if (mid * mid <= n)
        {
            res = mid;
            s = mid + 1;
        }
        else
            e = mid - 1;
    }
    double inc = 0.1;
    for (int i = 1; i <= p; i++)
    {
        while (res * res <= n)
        {
            res += inc;
        }
        res -= inc;
        inc /= 10;
    }
    return res;
}
int main()
{
    int n, p;
    cin >> n >> p;
    float res = getResult(n, p);
    cout << res << '\n';

    return 0;
}
