#include <bits/stdc++.h>
using namespace std;
int getFirst1(int *a, int n, int item)
{
    if (n == 0)
        return -1;
    if (a[0] == item)
        return 1;
    int ans = getFirst1(a + 1, n - 1, item);
    if (ans != -1)
        return 1 + ans;
    else
    {
        return -1;
    }
}
int getFirst2(int *a, int i, int n, int item)
{
    if (i == n)
    {
        return -1;
    }
    if (a[i] == item)
        return i;
    else
        return getFirst2(a, i + 1, n, item);
}
int main()
{
    int a[] = {1, 2, 2, 5, 6, 7, 7, 8};
    int n = sizeof(a) / sizeof(int);
    int ans = getFirst1(a, n, 5);
    int ans2 = getFirst2(a, 0, n, 33);

    cout << ans << " " << ans2 << '\n';
}