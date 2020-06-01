#include <bits/stdc++.h>
using namespace std;
int msb(int x)
{
    int temp = x;
    int pos = 0;
    while (temp)
    {
        // cout << temp << endl;

        // cout << "Kitni Baar Chala" << endl;
        pos++;

        temp = temp >> 1;
    }
    return pos - 1;
}
int main()
{
    int i, j;
    cin >> i;
    cin >> j;
    int x = i ^ j;
    // cout << "x= " << x;
    int pos = msb(x);
    // cout << "pos=" << pos << endl;
    int ans = 1;
    int t = 1;
    while (t <= pos)
    {
        ans = (ans << 1) + 1;
        t++;
    }
    cout << ans << endl;

    return 0;
}