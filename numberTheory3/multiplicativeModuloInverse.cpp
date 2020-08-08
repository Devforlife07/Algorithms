#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}
int x, y, g;
int a, b;
void extendedEuclids(int a, int b)
{
    if (y == 0)
    {
        x = 1, y = 0;
        g = a;
        return;
    }
    extendedEuclids(b, a % b);
    int currX = y;
    int currY = x - (a / b) * y;
    x = currX;
    y = currY;
}
void getResult()
{
    if (gcd(a, b) == 1)
    {
        extendedEuclids(a, b);
    }
    else
        cout << "Moudulo Inverse Do Not Exist"
             << "\n";
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> a >> b;
    getResult();
    cout << x << '\n';
    return 0;
}