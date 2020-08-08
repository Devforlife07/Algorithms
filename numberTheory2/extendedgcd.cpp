#include <bits/stdc++.h>
using namespace std;
int x, y, g;
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}
void extendedGCD(int a, int b)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        g = a;
        return;
    }
    extendedGCD(b, a % b);
    int cx = y;
    int cy = x - (a / b) * y;
    x = cx;
    y = cy;
}
int main()
{
 
    int a, b;
    cin >> a >> b;
    extendedGCD(a, b);
    cout << x << " " << y << '\n';
}