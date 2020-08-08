#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool binarySearch(int s, int e, int a[], int n, int key)
{
    if (s > e)
    {
        return false;
    }
    int mid = (s + e) / 2;
    if (key > a[mid])
    {
        return binarySearch(s + 1, e, a, n, key);
    }
    else if (key < a[mid])
    {
        return binarySearch(s, mid - 1, a, n, key);
    }
    else
        return true;
}
int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a[] = {1, 2, 3, 4, 5};
    int n = sizeof(a) / sizeof(int);
    cout << binarySearch(0, n - 1, a, n, 6) << '\n';

    return 0;
}