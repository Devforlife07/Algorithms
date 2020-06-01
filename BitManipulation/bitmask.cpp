#include <bits/stdc++.h>
// #include <iostream>
using namespace std;
int get(int n, int i)
{
    int mask = (1 << i);
    return ((n & mask) > 0 ? 1 : 0);
}
int main()
{
    int ans = get(7, 3);
    cout << ans << endl;

    return 0;
}