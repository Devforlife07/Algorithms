#include <bits/stdc++.h>
using namespace std;
bool isPossible(int *a, int n, int mid, int m)
{
    int curr = 0;
    int student = 1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > mid)
        {
            return false;
        }
        if (curr + a[i] > mid)
        {
            curr = a[i];
            student++;

            if (student > m)
                return false;
        }
        else
        {
            curr += a[i];
        }
    }

    return true;
}
int main()
{
    int a[] = {10, 20, 30, 40};
    int n = sizeof(a) / sizeof(a[0]);
    int m = 2;
    int s = 0;
    int e = accumulate(a, a + n, s);
    int ans = 0;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        if (isPossible(a, n, mid, m))
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    cout << ans << endl;

    return 0;
}