    #include <bits/stdc++.h>
using namespace std;
int getResult(int a[], int n, int key, int s, int e)
{
    if (s > e)
        return -1;
    int mid = (s + e) / 2;
    if (a[mid] == key)
        return mid;
    if (a[s] <= a[mid])
    {
        if (key >= a[s] and key <= a[mid])
            return getResult(a, n, key, s, mid - 1);
        return getResult(a, n, key, mid + 1, e);
    }
    if (key >= a[mid] and key <= a[e])
        return getResult(a, n, key, mid + 1, e);
    return getResult(a, n, s, mid - 1, key);
}
int main()
{
    int a[] = {3, 4, 5, 6, 7, 8, 9, 1, 2};
    int n = sizeof(a) / sizeof(a[0]);
    int key = 5;
    int ans = getResult(a, n, key, 0, n - 1);
    cout << ans << '\n';

    return 0;
}