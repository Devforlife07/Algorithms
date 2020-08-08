#include <bits/stdc++.h>
using namespace std;
int lastOccurence(int *a, int n, int item)
{
    if (n == 0)
        return -1;
    int ans = lastOccurence(a + 1, n - 1, item);
    if (ans == -1)
    {
        if (a[0] == item)
            return 1;
        else
        {
            return -1;
        }
    }
    else
        return 1 + ans;
}
int main()
{
    int a[] = {1, 2, 3, 4, 5, 3, 6, 7, 6};
    int n = sizeof(a) / sizeof(int);
    int ans = lastOccurence(a, n, 7);
    cout << ans << '\n';
}